# include "Lights.h"
#include <string>
#include <iostream>


void Light::update_uniforms() {
	std::cout << "[WARNING] light.update_uniforms(index) executed" << std::endl;
}

AmbiantLight::AmbiantLight(const glm::vec3& color, Program& program) :
	color(color), program(&program) {}

void AmbiantLight::update_uniforms() {
	std::string uniform_name = shader_name + "[" + std::to_string(count) + "]";
	program->update_uniform(uniform_name + ".color", color.x, color.y, color.z);

	// temp
	count++;
	program->update_uniform(shader_name+"_count", count);
}

int AmbiantLight::count = 0;

DirectionalLight::DirectionalLight(const glm::vec3& direction, const glm::vec3& color, Program& program) :
	direction(direction), color(color), program(&program) {}

void DirectionalLight::update_uniforms() {
	std::string uniform_name = shader_name + "[" + std::to_string(count) + "]";
	program->update_uniform(uniform_name + ".direction", direction.x, direction.y, direction.z);
	program->update_uniform(uniform_name + ".color", color.x, color.y, color.z);

	// temp
	count++;
	program->update_uniform(shader_name + "_count", count);
}

int	DirectionalLight::count = 0;

PointLight::PointLight(const glm::vec3& position, const glm::vec3& color, float constant_term, float linear_term, float exponential_term, Program& program) :
	position(position), color(color), constant_term(constant_term), linear_term(linear_term), exponential_term(exponential_term), program(&program) {}

void PointLight::update_uniforms() {
	std::string uniform_name = shader_name + "[" + std::to_string(count) + "]";
	program->update_uniform(uniform_name + ".position", position.x, position.y, position.z);
	program->update_uniform(uniform_name + ".color", color.x, color.y, color.z);
	program->update_uniform(uniform_name + ".constant_term", constant_term);
	program->update_uniform(uniform_name + ".linear_term", linear_term);
	program->update_uniform(uniform_name + ".exponential_term", exponential_term);
	
	// temp
	count++;
	program->update_uniform(shader_name + "_count", count);
}

int PointLight::count = 0;


SpotLight::SpotLight(const glm::vec3& position, const glm::vec3& direction,  const glm::vec3& color, float constant_term, float linear_term, float exponential_term, float angle, Program& program) :
	position(position), direction(direction), color(color), constant_term(constant_term), linear_term(linear_term), exponential_term(exponential_term), angle(angle), program(&program) {}

void SpotLight::update_uniforms() {
	std::string uniform_name = shader_name + "[" + std::to_string(count) + "]";
	program->update_uniform(uniform_name + ".position", position.x, position.y, position.z);
	program->update_uniform(uniform_name + ".direction", direction.x, direction.y, direction.z);
	program->update_uniform(uniform_name + ".color", color.x, color.y, color.z);
	program->update_uniform(uniform_name + ".constant_term", constant_term);
	program->update_uniform(uniform_name + ".linear_term", linear_term);
	program->update_uniform(uniform_name + ".exponential_term", exponential_term);
	program->update_uniform(uniform_name + ".cos_angle", glm::cos(glm::radians(angle)));

	// temp
	count++;
	program->update_uniform(shader_name + "_count", count);
}

int SpotLight::count = 0;