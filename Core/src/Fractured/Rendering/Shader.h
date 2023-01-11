#pragma once
#include "glm/glm.hpp"

namespace FracturedInternal::Render
{
	class Shader
	{
	public:
		Shader() = default;

		void BuildShader(const std::string& vertexPath, const std::string& fragmentPath);
		void ActivateShader();

		void SetBool(const std::string& name, bool value)	  const;
		void SetInt(const std::string& name, int value)		  const;
		void SetFloat(const std::string& name, float value)	  const;
		void SetVec2(const std::string& name, glm::vec2& vec) const;
		void SetVec3(const std::string& name, glm::vec3& vec) const;
		void SetVec4(const std::string& name, glm::vec4& vec) const;
		void SetMat4(const std::string& name, glm::mat4& mat) const;

		[[nodiscard]] fint32 GetId() const { return  id; }
	private: 
		fint32 id;
	private:
		void CheckCompileErrors(fint32 shader, const std::string& type);
	};
}

