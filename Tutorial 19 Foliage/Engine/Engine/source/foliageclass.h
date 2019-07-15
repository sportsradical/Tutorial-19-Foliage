////////////////////////////////////////////////////////////////////////////////
// Filename: foliageclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _FOLIAGECLASS_H_
#define _FOLIAGECLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <time.h> 
#include <DirectXMath.h>
using namespace DirectX;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: FoliageClass
////////////////////////////////////////////////////////////////////////////////
class FoliageClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

	struct FoliageType
	{
		float x, z;
		float r, g, b;
	};

	struct InstanceType
	{
		XMMATRIX matrix;
		XMFLOAT3 color;
	};

public:
	FoliageClass();
	FoliageClass(const FoliageClass&);
	~FoliageClass();

	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* textureFilename, int fCount);
	void Shutdown();
	void Render(ID3D11DeviceContext* deviceContext);
	bool Frame(XMFLOAT3, ID3D11DeviceContext* deviceContext);

	int GetVertexCount();
	int GetInstanceCount();

	ID3D11ShaderResourceView* GetTexture();

private:
	bool InitializeBuffers(ID3D11Device* device);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext* deviceContext);

	bool LoadTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename);
	void ReleaseTexture();

	bool GeneratePositions();

private:
	int m_foliageCount;
	FoliageType* m_foliageArray;
	InstanceType* m_Instances;
	ID3D11Buffer *m_vertexBuffer, *m_instanceBuffer;
	int m_vertexCount, m_instanceCount;
	TextureClass* m_Texture;
	float m_windRotation;
	int m_windDirection;
};

#endif