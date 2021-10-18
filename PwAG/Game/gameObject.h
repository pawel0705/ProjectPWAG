#pragma once
#include "pch.h"
#include "src/Rendering system/Shader/shaderProgram.h"
#include "texture.h"
#include "material.h"
#include "mesh.h"

class GameObject
{
public:
	GameObject();
	GameObject(
		Material* material,
		Texture* texture,
		std::vector<DataOBJ> mesh,
		glm::vec3 objectPosition = glm::vec3(1.f),
		glm::vec3 objectOrigin = glm::vec3(0.f),
		glm::vec3 objectRotation = glm::vec3(0.f),
		glm::vec3 objectScale = glm::vec3(1.f));

	void Draw(ShaderProgram* shaderProgram);

	void SetPosition(const glm::vec3 position);
	void SetOrigin(const glm::vec3 origin);
	void SetRotation(const glm::vec3 rotation);
	void SetScale(const glm::vec3 scale);

	glm::vec3 GetPosition();

	~GameObject();

private:
	struct {
		glm::vec3 objectPosition;
		glm::vec3 objectOrigin;
		glm::vec3 objectRotation;
		glm::vec3 objectScale;
	} transformation;

	Texture* texture;
	Material* material;
	Mesh* mesh;
};

