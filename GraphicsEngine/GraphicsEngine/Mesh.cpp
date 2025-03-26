#include <GL/glew.h>
#include "Mesh.h"

void Mesh::SetTriangleData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices) {
	std::vector<Vertex> _vertices = {
		// Vertex 0 (bottom left)
		{ 
			{ -1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 0.0f, 0.0f },	// Color
			{ 0.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 1 (bottom right)
		{ 
			{ 1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 1.0f, 0.0f },	// Color
			{ 1.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 2 (top)
		{ 
			{ 0.0f, 1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 0.5f, 1.0f }			// Texture Coordinate
		}
	};

	std::vector<uint32_t> _indices = {
		0, 1, 2
	};

	vertices.clear(); indices.clear();
	vertices = _vertices;
	indices = _indices;
}

void Mesh::SetQuadData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
	std::vector<Vertex> _vertices = {
		// Vertex 0 (top right)
		{
			{ 1.0f, 1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 1.0f, 1.0f }			// Texture Coordinate
		},
		// Vertex 1 (bottom right)
		{
			{ 1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 1.0f, 0.0f },	// Color
			{ 1.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 2 (bottom left)
		{
			{ -1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 0.0f, 0.0f },	// Color
			{ 0.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 3 (top left)
		{
			{ -1.0f, 1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 0.0f, 1.0f }			// Texture Coordinate
		}
	};

	std::vector<uint32_t> _indices = {
		0, 1, 3,
		1, 2, 3
	};

	vertices.clear(); indices.clear();
	vertices = _vertices;
	indices = _indices;
}

void Mesh::SetCubeData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
	std::vector<Vertex> _vertices = {
		// Vertex 0 (top right front)
		{
			{ 1.0f, 1.0f, 1.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 1.0f, 1.0f }			// Texture Coordinate
		},
		// Vertex 1 (bottom right front)
		{
			{ 1.0f, -1.0f, 1.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 1.0f, 0.0f },	// Color
			{ 1.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 2 (bottom left front)
		{
			{ -1.0f, -1.0f, 1.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 0.0f, 0.0f },	// Color
			{ 0.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 3 (top left front)
		{
			{ -1.0f, 1.0f, 1.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 0.0f, 1.0f }			// Texture Coordinate
		},
		// Vertex 4 (top right back)
		{
			{ 1.0f, 1.0f, -1.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 1.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 5 (bottom right back)
		{
			{ 1.0f, -1.0f, -1.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 1.0f, 0.0f },	// Color
			{ 1.0f, 1.0f }			// Texture Coordinate
		},
		// Vertex 6 (bottom left back)
		{
			{ -1.0f, -1.0f, -1.0f },// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 0.0f, 0.0f },	// Color
			{ 1.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 7 (top left back)
		{
			{ -1.0f, 1.0f, -1.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 0.0f, 0.0f }			// Texture Coordinate
		}
	};

	std::vector<uint32_t> _indices = {
		// Front
		0, 1, 2,
		0, 2, 3,
		// Top
		0, 3, 4,
		3, 4, 7,
		// Right
		0, 1, 5,
		0, 4, 5,
		//Left
		2, 3, 6,
		3, 6, 7,
		// Back
		4, 5, 6,
		5, 6, 7,
		// Bottom
		1, 2, 5,
		2, 5,6
	};

	vertices.clear(); indices.clear();
	vertices = _vertices;
	indices = _indices;
}

void Mesh::SetSphereData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
}
