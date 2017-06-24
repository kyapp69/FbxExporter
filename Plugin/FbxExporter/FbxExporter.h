#pragma once

#ifdef _WIN32
    #define fbxeAPI extern "C" __declspec(dllexport)
#else
    #define fbxeAPI extern "C" 
#endif

using namespace mu;

namespace fbxe {
    using Node = void;
    class IContext;

    enum class Topology
    {
        Points,
        Lines,
        Triangles,
        Quads,
    };

    enum class Format
    {
        FBXBinary,
        FBXAscii,
        FBXEncrypted,
        Obj,
    };
} // namespace fbxe


fbxeAPI fbxe::IContext* fbxeCreateContext();
fbxeAPI void            fbxeReleaseContext(fbxe::IContext *ctx);

fbxeAPI bool        fbxeCreateScene(fbxe::IContext *ctx, const char *name);
fbxeAPI bool        fbxeWrite(fbxe::IContext *ctx, const char *path, fbxe::Format format);

fbxeAPI fbxe::Node* fbxeGetRootNode(fbxe::IContext *ctx);
fbxeAPI fbxe::Node* fbxeFindNodeByName(fbxe::IContext *ctx, const char *name);

fbxeAPI fbxe::Node* fbxeCreateNode(fbxe::IContext *ctx, fbxe::Node *parent, const char *name);
fbxeAPI void        fbxeSetTRS(fbxe::IContext *ctx, fbxe::Node *node, float3 t, quatf r, float3 s);
fbxeAPI void        fbxeAddMesh(fbxe::IContext *ctx, fbxe::Node *node, fbxe::Topology topology, int num_indices, int num_vertices,
    const int indices[], const float3 points[], const float3 normals[], const float4 tangents[], const float2 uv[], const float4 colors[]);
fbxeAPI void        fbxeAddSkin(fbxe::IContext *ctx, fbxe::Node *node, Weights4 weights[], fbxe::Node *bones[], float4x4 bindposes[], int num_bones);
