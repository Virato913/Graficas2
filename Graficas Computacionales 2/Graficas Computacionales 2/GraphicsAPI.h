#pragma once

#include <windows.h>

#include "GraphicsData.h"
#include "Camera.h"
#include "Model.h"
#include "Shader.h"

const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsAPI
{
private:
	GraphicsData* m_Data;
	Camera* m_Camera;
	Model* m_Model;
	Shader* m_ColorShader;
	Texture2D* m_TextureShader;

	bool Render()
	{
		XMMATRIX *worldMatrix, *viewMatrix, *projectionMatrix;
		bool result;
		worldMatrix = new XMMATRIX();
		viewMatrix = new XMMATRIX();
		projectionMatrix = new XMMATRIX();

		// Clear the buffers to begin the scene.
		m_Data->BeginScene();

		// Generate the view matrix based on the camera's position.
		m_Camera->Render();

		// Get the world, view, and projection matrices from the camera and d3d objects.
		m_Data->GetWorldMatrix(*worldMatrix);
		m_Camera->GetViewMatrix(*viewMatrix);
		m_Data->GetProjectionMatrix(*projectionMatrix);

		// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
		m_Model->Render(m_Data->GetDeviceContext());

		// Render the model using the color shader.
		result = m_ColorShader->Render(m_Data->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture());
		if (!result)
		{
			return false;
		}

		// Present the rendered scene to the screen.
		m_Data->EndScene();

		return true;
	}

public:
	GraphicsAPI()
	{
		m_Data = nullptr;
		m_Camera = nullptr;
		m_Model = nullptr;
		m_ColorShader = nullptr;
		m_TextureShader = nullptr;
	}

	GraphicsAPI(const GraphicsAPI& other)
	{

	}

	~GraphicsAPI()
	{

	}

	bool Initialize(HWND hWnd)
	{
		bool result;

		RECT rc;
		GetClientRect(hWnd, &rc);
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

		// Create the Direct3D object.
		m_Data = new GraphicsData;
		if (!m_Data)
		{
			return false;
		}

		// Initialize the Direct3D object.
		result = m_Data->Initialize(hWnd, SCREEN_DEPTH, SCREEN_NEAR);
		if (!result)
		{
			MessageBox(hWnd, L"Could not initialize Direct3D", L"Error", MB_OK);
			return false;
		}

		// Create the camera object.
		m_Camera = new Camera();
		if (!m_Camera)
		{
			return false;
		}

		// Set the initial position of the camera.
		m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

		// Create the model object.
		m_Model = new Model();
		if (!m_Model)
		{
			return false;
		}

		// Initialize the model object.
		result = m_Model->Initialize(m_Data->GetDevice(), m_Data->GetDeviceContext(), height, width, "../Debug/stone01.tga");
		if (!result)
		{
			MessageBox(hWnd, L"Could not initialize the model object.", L"Error", MB_OK);
			return false;
		}

		// Create the color shader object.
		m_ColorShader = new Shader;
		if (!m_ColorShader)
		{
			return false;
		}

		// Initialize the color shader object.
		result = m_ColorShader->Initialize(m_Data->GetDevice(), hWnd);
		if (!result)
		{
			MessageBox(hWnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
			return false;
		}

		return true;
	}

	void Shutdown()
	{
		// Release the texture shader object.
		if (m_TextureShader)
		{
			m_TextureShader->Shutdown();
			delete m_TextureShader;
			m_TextureShader = 0;
		}

		// Release the Shader object.
		if (m_ColorShader)
		{
			m_ColorShader->Shutdown();
			delete m_ColorShader;
			m_ColorShader = 0;
		}

		// Release the Model object.
		if (m_Model)
		{
			m_Model->Shutdown();
			delete m_Model;
			m_Model = 0;
		}

		// Release the Camera object.
		if (m_Camera)
		{
			delete m_Camera;
			m_Camera = 0;
		}

		// Release the GraphicsData object.
		if (m_Data)
		{
			m_Data->Shutdown();
			delete m_Data;
			m_Data = 0;
		}
	}

	bool Frame()
	{
		bool result;


		// Render the graphics scene.
		result = Render();
		if (!result)
		{
			return false;
		}

		return true;
	}
};

