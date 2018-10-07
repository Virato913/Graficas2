#include "stdafx.h"
#include "Device.h"

CDevice::CDevice()
{
	m_Device = nullptr;
}

CDevice::~CDevice()
{
	Clear();
}

HRESULT CDevice::Init(CDeviceContext* deviceContext, CSwapChain* swapChain, HWND hWnd, UINT width, UINT height)
{
	HRESULT hr = S_OK;

	unsigned int createDeviceFlags = 0;

#if defined(_DEBUG)
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	vector<D3D_DRIVER_TYPE> driverTypes;
	driverTypes.push_back(D3D_DRIVER_TYPE_HARDWARE);
	driverTypes.push_back(D3D_DRIVER_TYPE_WARP);
	driverTypes.push_back(D3D_DRIVER_TYPE_REFERENCE);

	vector<D3D_FEATURE_LEVEL> featureLevels;
	featureLevels.push_back(D3D_FEATURE_LEVEL_11_0);
	featureLevels.push_back(D3D_FEATURE_LEVEL_10_1);
	featureLevels.push_back(D3D_FEATURE_LEVEL_10_0);

	DXGI_SWAP_CHAIN_DESC sd;
	memset(&sd, 0, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = width;
	sd.BufferDesc.Height = height;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = true;

	D3D_FEATURE_LEVEL selectedFL;

	for (size_t driverTypeIndex = 0; driverTypeIndex < driverTypes.size(); ++driverTypeIndex)
	{
		D3D_DRIVER_TYPE& dt = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(nullptr, dt, nullptr, createDeviceFlags, &featureLevels[0], static_cast<UINT>(featureLevels.size()), D3D11_SDK_VERSION, &sd, swapChain->GetSwapChain(), &m_Device, &selectedFL, deviceContext->GetDeviceContext());
		if (SUCCEEDED(hr))
		{
			break;
		}
	}

	return hr;
}

HRESULT CDevice::CreateBackBuffer(CRenderTargetView* renderTargetView, CSwapChain* swapChain)
{
	CTexture2D* backBuffer = new CTexture2D();
	HRESULT hr = swapChain->GetBuffer(backBuffer);
	if (FAILED(hr))
		return hr;
	hr = m_Device->CreateRenderTargetView(backBuffer->GetTexture(), NULL, renderTargetView->GetRTV());
	backBuffer->Clear();
	return hr;
}

void CDevice::Clear()
{
	if (m_Device)
		m_Device->Release();
}

ID3D11Device* CDevice::GetDevice()
{
	return m_Device;
}