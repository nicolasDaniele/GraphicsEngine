#pragma once

#include <vector>
#include "Libraries/glm/glm/glm.hpp"

enum MeshType {
	MT_Triangle = 0,
	MT_Quad = 1,
	MT_Cube = 2,
	MT_Sphere = 3
};

struct Vertex {
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texCoords;
};

class Mesh {
public:
	static void SetTriangleData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	static void SetQuadData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	static void SetCubeData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	static void SetSphereData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
};