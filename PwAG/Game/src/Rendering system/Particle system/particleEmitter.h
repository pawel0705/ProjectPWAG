#pragma once
#include "particle.h"
#include "../Texture/texture.h"

class ParticleEmitter
{
public:
	ParticleEmitter(const glm::vec3& position, const Texture& texture, const glm::vec3& scale = { 1.0, 1.0, 1.0 });
	ParticleEmitter(const ParticleEmitter&) = delete;
	ParticleEmitter(ParticleEmitter&&) noexcept;

	ParticleEmitter& operator=(const ParticleEmitter&) = delete;
	ParticleEmitter& operator=(ParticleEmitter&&) noexcept;

	void update(float deltaTime);

	void render(const ShaderProgram& shader);

#pragma region Inline functions
	bool isActive() const
	{
		return active;
	}
	const glm::vec3& getPosition() const
	{
		return position;
	}

	void setActive(bool isActive)
	{
		this->active = isActive;
	}
#pragma endregion
private:
	bool active = true;

	glm::vec3 position;
	glm::vec3 scale;
	const Texture* texture;

	static uint32_t maxParticles;
	std::vector<Particle> particles;

	const float timeToCreateAnotherParticle = 0.4f;
	float timePassed = 0.0f;
};

