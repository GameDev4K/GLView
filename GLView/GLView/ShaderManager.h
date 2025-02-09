﻿#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "Texture.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class ShaderManager
{
private:
    GLuint shaderProgram;
    GLuint CompileShader(GLenum type, std::string code);
    std::string vertexShaderCode;
    std::string fragmentShaderCode;
    std::string vertexShaderCodePath = "";
    std::string fragmentShaderCodePath = "";
    std::string compilerErrors = "";
    bool recompiling = false;
    bool compilingFailed = false;
    Texture textures[16];

    bool ReadFile(std::string path, std::string &content);
    static std::string resolveIncludePath(std::string parentPath, std::string includePath);

public:
    ShaderManager();
    void Destroy();
    bool Compile();
    void Recompile();
    void Use();
    bool LoadVertexShader(std::string path);
    bool LoadFragmentShader(std::string path);
    void AssignTextureHooks(GLuint* hooks);
    bool SetUniformInt(std::string key, int value);
    bool SetUniformFloat(std::string key, float value);
    bool SetUniformFloat2(std::string key, float v1, float v2);
    bool SetUniformFloat3(std::string key, float v1, float v2, float v3);
    bool SetUniformFloat4(std::string key, float v1, float v2, float v3, float v4);
    bool SetUniformMat4(std::string key, float* value_ptr);
    
    bool IsCompilingFailed()
    {
        return compilingFailed;
    }
    std::string GetCompilingErrors()
    {
        return compilerErrors;
    }
    std::string GetFragmentShaderPath()
    {
        return fragmentShaderCodePath;
    }
    std::string GetVertexShaderPath()
    {
        return vertexShaderCodePath;
    }

    void bindTextures();
    void createTextures();
};