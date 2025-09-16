/**
 * \file
 * \author Rudy Castan
 * \author Taekyung Ho
 * \date 2025 Fall
 * \par CS200 Computer Graphics I
 * \copyright DigiPen Institute of Technology
 */
#include "DemoMyModel.hpp"
#include "CS200/RenderingAPI.hpp"
#include "DemoVAO.hpp"
#include "Engine/Engine.hpp"
#include "Engine/GameStateManager.hpp"
#include "OpenGL/GL.hpp"
#include "OpenGL/Shader.hpp"
#include "OpenGL/VertexArray.hpp"
#include <algorithm>
#include <imgui.h>

void DemoMyModel::Load()
{
    using filepath = std::filesystem::path;
    simpleShader   = OpenGL::CreateShader(filepath{ "Assets/shaders/pass_thru_pos2d_clr.vert" }, filepath{ "Assets/shaders/basic_vtx_clr_attribute.frag" });

    GL::GenBuffers(static_cast<GLsizei>(bufferHandles.size()), bufferHandles.data());
    GL::GenBuffers(static_cast<GLsizei>(indexBufferHandles.size()), indexBufferHandles.data());

    // create_1buffer_struct_of_arrays_style();
    // create_1buffer_array_of_structs_style();
    // create_parallel_buffers_style();
    create_1stmodel_1buffer_array_of_structs_style();
    create_2ndmodel_1buffer_array_of_structs_style();
    create_3rdmodel_1buffer_array_of_structs_style();
    create_4thmodel_1buffer_array_of_structs_style();
    create_5thmodel_1buffer_array_of_structs_style();
}

void DemoMyModel::Unload()
{
    OpenGL::DestroyShader(simpleShader);
    GL::DeleteVertexArrays(1, &firstModel), firstModel   = 0;
    GL::DeleteVertexArrays(1, &secondModel), secondModel = 0;
    GL::DeleteVertexArrays(1, &thirdModel), thirdModel   = 0;
    GL::DeleteVertexArrays(1, &forthModel), forthModel   = 0;
    GL::DeleteVertexArrays(1, &fifthModel), fifthModel   = 0;
    GL::DeleteBuffers(static_cast<GLsizei>(bufferHandles.size()), bufferHandles.data());
    std::fill(std::begin(bufferHandles), std::end(bufferHandles), 0);
    GL::DeleteBuffers(static_cast<GLsizei>(indexBufferHandles.size()), indexBufferHandles.data());
    std::fill(std::begin(indexBufferHandles), std::end(indexBufferHandles), 0);
}

void DemoMyModel::Update()
{
    // hue += 0.25f;
    // if (hue >= 360.0f)
    //     hue -= 360.0f;
}

void DemoMyModel::Draw() const
{
    constexpr GLsizei        indices_count            = 6;
    constexpr GLenum         primitive_pattern        = GL_TRIANGLES;
    constexpr GLenum         firstmodel_indices_type  = GL_UNSIGNED_INT;
    constexpr GLenum         secondmodel_indices_type = GL_UNSIGNED_INT;
    constexpr GLenum         thirdmodel_indices_type  = GL_UNSIGNED_INT;
    constexpr GLenum         forthmodel_indices_type  = GL_UNSIGNED_INT;
    constexpr GLenum         fifthmodel_indices_type  = GL_UNSIGNED_INT;
    constexpr GLvoid*        byte_offset_into_indices = nullptr;
    constexpr OpenGL::Handle no_object                = 0;

    calculate_and_set_clear_color();
    CS200::RenderingAPI::Clear();

    GL::UseProgram(simpleShader.Shader);

    GL::BindVertexArray(firstModel);
    GL::DrawElements(primitive_pattern, indices_count, firstmodel_indices_type, byte_offset_into_indices);

    GL::BindVertexArray(secondModel);
    GL::DrawElements(primitive_pattern, indices_count, secondmodel_indices_type, byte_offset_into_indices);

    GL::BindVertexArray(thirdModel);
    GL::DrawElements(primitive_pattern, indices_count, thirdmodel_indices_type, byte_offset_into_indices);

    GL::BindVertexArray(forthModel);
    GL::DrawElements(primitive_pattern, indices_count, forthmodel_indices_type, byte_offset_into_indices);

    GL::BindVertexArray(fifthModel);
    GL::DrawElements(primitive_pattern, indices_count, fifthmodel_indices_type, byte_offset_into_indices);

    GL::BindVertexArray(no_object);
    GL::UseProgram(no_object);
}

void DemoMyModel::DrawImGui()
{
    ImGui::Begin("Program Info");
    {
        ImGui::LabelText("FPS", "%d", Engine::GetWindowEnvironment().FPS);
        {
            float r = 0, g = 0, b = 0;
            ImGui::ColorConvertHSVtoRGB(hue / 360.0f, saturation, value, r, g, b);
            ImGui::LabelText("Background Color", "RGB(%.0f,%.0f,%.0f)", static_cast<double>(r * 255), static_cast<double>(g * 255), static_cast<double>(b * 255));
        }


        ImGui::Separator();
        if (ImGui::Button("Switch to VAO Demo"))
        {
            Engine::GetGameStateManager().PopState();
            Engine::GetGameStateManager().PushState<DemoVAO>();
        }
    }
    ImGui::End();
}

DemoMyModel::~DemoMyModel()
{
    Unload();
}

void DemoMyModel::calculate_and_set_clear_color() const
{
    float r = 0, g = 0, b = 0;
    ImGui::ColorConvertHSVtoRGB(hue / 360.0f, saturation, value, r, g, b);
    GL::ClearColor(r, g, b, 1.0f);
}

namespace
{
    struct vec2
    {
        float x = 0;
        float y = 0;
    };

    struct color3
    {
        float r = 0;
        float g = 0;
        float b = 0;
    };
}

namespace
{
    struct Vertex
    {
        vec2   position{};
        color3 color{};
    };

}

void DemoMyModel::create_1stmodel_1buffer_array_of_structs_style()
{
    constexpr float      r        = 0.819607843137f;
    constexpr float      g        = 0.706666666666f;
    constexpr float      b        = 0.988235294118f;
    constexpr std::array vertices = {
        Vertex{ vec2{ 0.125f, 0.375f }, color3{ r, g, b } },
        Vertex{ vec2{ 0.125f, -0.25f }, color3{ r, g, b } },
        Vertex{ vec2{ 0.25f, -0.125f }, color3{ r, g, b } },
        Vertex{   vec2{ 0.25f, 0.25f }, color3{ r, g, b } }
    };
    constexpr std::array<unsigned, 6> indices = { 0, 1, 2, 2, 3, 0 };

    const auto& firstModelVertBuffer  = bufferHandles[0];
    const auto& firstModelIndexBuffer = indexBufferHandles[0];

    GL::BindBuffer(GL_ARRAY_BUFFER, firstModelVertBuffer);
    GL::BufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ARRAY_BUFFER, 0);

    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, firstModelIndexBuffer);
    GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    const auto layout = OpenGL::VertexBuffer{ firstModelVertBuffer, OpenGL::BufferLayout{ { OpenGL::Attribute::Float2, OpenGL::Attribute::Float3 } } };
    firstModel        = OpenGL::CreateVertexArrayObject(layout, firstModelIndexBuffer);
}

void DemoMyModel::create_2ndmodel_1buffer_array_of_structs_style()
{
    constexpr float      r        = 0.623529411765f;
    constexpr float      g        = 0.454901960784f;
    constexpr float      b        = 0.847058823529f;
    constexpr std::array vertices = {
        Vertex{     vec2{ -0.25f, 0.25f }, color3{ r, g, b } },
        Vertex{ vec2{ -0.3125f, 0.1875f }, color3{ r, g, b } },
        Vertex{    vec2{ 0.125f, -0.25f }, color3{ r, g, b } },
        Vertex{   vec2{ 0.125f, -0.125f }, color3{ r, g, b } }
    };
    constexpr std::array<unsigned, 6> indices = { 0, 1, 2, 2, 3, 0 };

    const auto& secondModelVertBuffer  = bufferHandles[1];
    const auto& secondModelIndexBuffer = indexBufferHandles[1];

    GL::BindBuffer(GL_ARRAY_BUFFER, secondModelVertBuffer);
    GL::BufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ARRAY_BUFFER, 0);

    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, secondModelIndexBuffer);
    GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    const auto layout = OpenGL::VertexBuffer{ secondModelVertBuffer, OpenGL::BufferLayout{ { OpenGL::Attribute::Float2, OpenGL::Attribute::Float3 } } };
    secondModel       = OpenGL::CreateVertexArrayObject(layout, secondModelIndexBuffer);
}

void DemoMyModel::create_3rdmodel_1buffer_array_of_structs_style()
{
    constexpr float      r        = 0.447058823529f;
    constexpr float      g        = 0.321568627451f;
    constexpr float      b        = 0.666666666666f;
    constexpr std::array vertices = {
        Vertex{   vec2{ -0.125f, 0.125f }, color3{ r, g, b } },
        Vertex{ vec2{ -0.0625f, 0.0625f }, color3{ r, g, b } },
        Vertex{     vec2{ 0.125f, 0.25f }, color3{ r, g, b } },
        Vertex{    vec2{ 0.125f, 0.375f }, color3{ r, g, b } }
    };
    constexpr std::array<unsigned, 6> indices = { 0, 1, 2, 2, 3, 0 };

    const auto& thirdModelVertBuffer  = bufferHandles[2];
    const auto& thirdModelIndexBuffer = indexBufferHandles[2];

    GL::BindBuffer(GL_ARRAY_BUFFER, thirdModelVertBuffer);
    GL::BufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ARRAY_BUFFER, 0);

    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, thirdModelIndexBuffer);
    GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    const auto layout = OpenGL::VertexBuffer{ thirdModelVertBuffer, OpenGL::BufferLayout{ { OpenGL::Attribute::Float2, OpenGL::Attribute::Float3 } } };
    thirdModel        = OpenGL::CreateVertexArrayObject(layout, thirdModelIndexBuffer);
}

void DemoMyModel::create_4thmodel_1buffer_array_of_structs_style()
{
    constexpr float      r        = 0.447058823529f;
    constexpr float      g        = 0.321568627451f;
    constexpr float      b        = 0.666666666666f;
    constexpr std::array vertices = {
        Vertex{ vec2{ -0.3125f, -0.0625f }, color3{ r, g, b } },
        Vertex{    vec2{ -0.25f, -0.125f }, color3{ r, g, b } },
        Vertex{       vec2{ -0.125f, 0.f }, color3{ r, g, b } },
        Vertex{  vec2{ -0.1875f, 0.0625f }, color3{ r, g, b } }
    };
    constexpr std::array<unsigned, 6> indices = { 0, 1, 2, 2, 3, 0 };

    const auto& forthModelVertBuffer  = bufferHandles[3];
    const auto& forthModelIndexBuffer = indexBufferHandles[3];

    GL::BindBuffer(GL_ARRAY_BUFFER, forthModelVertBuffer);
    GL::BufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ARRAY_BUFFER, 0);

    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, forthModelIndexBuffer);
    GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    const auto layout = OpenGL::VertexBuffer{ forthModelVertBuffer, OpenGL::BufferLayout{ { OpenGL::Attribute::Float2, OpenGL::Attribute::Float3 } } };
    forthModel        = OpenGL::CreateVertexArrayObject(layout, forthModelIndexBuffer);
}

void DemoMyModel::create_5thmodel_1buffer_array_of_structs_style()
{
    constexpr float      r        = 0.36862745098f;
    constexpr float      g        = 0.262745098039f;
    constexpr float      b        = 0.560784313725f;
    constexpr std::array vertices = {
        Vertex{  vec2{ -0.3125f, 0.1875f }, color3{ r, g, b } },
        Vertex{ vec2{ -0.3125f, -0.0625f }, color3{ r, g, b } },
        Vertex{        vec2{ -0.25f, 0.f }, color3{ r, g, b } },
        Vertex{     vec2{ -0.25f, 0.125f }, color3{ r, g, b } }
    };
    constexpr std::array<unsigned, 6> indices = { 0, 1, 2, 2, 3, 0 };

    const auto& fifthModelVertBuffer  = bufferHandles[4];
    const auto& fifthModelIndexBuffer = indexBufferHandles[4];

    GL::BindBuffer(GL_ARRAY_BUFFER, fifthModelVertBuffer);
    GL::BufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ARRAY_BUFFER, 0);

    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, fifthModelIndexBuffer);
    GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    const auto layout = OpenGL::VertexBuffer{ fifthModelVertBuffer, OpenGL::BufferLayout{ { OpenGL::Attribute::Float2, OpenGL::Attribute::Float3 } } };
    fifthModel        = OpenGL::CreateVertexArrayObject(layout, fifthModelIndexBuffer);
}
