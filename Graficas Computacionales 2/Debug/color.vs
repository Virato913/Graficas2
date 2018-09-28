////////////////////////////////////////////////////////////////////////////////
// Filename: color.vs
////////////////////////////////////////////////////////////////////////////////


//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    //float4 color : COLOR0;
    float4 position : POSITION0;
	float2 texCoords : TEXCOORD0;
};

struct PixelInputType
{
    //float4 color : COLOR0;
    float4 position : SV_POSITION;
	float2 texCoords : TEXCOORD0;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType ColorVertexShader(VertexInputType input)
{
    PixelInputType output = (PixelInputType)0;
    
	//output.color = input.color;
	output.texCoords = input.texCoords;
	output.position = float4(input.position.xyz, 1);
    
    return output;
}