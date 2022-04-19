#pragma pack_matrix(row_major)

struct INPUT_VERTEX
{
    float4 pos : POSITION;
};

struct OUTPUT_VERTEX
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

OUTPUT_VERTEX main(INPUT_VERTEX intovertexBuffer)
{
    OUTPUT_VERTEX sendtoPixel;
    sendtoPixel.position = intovertexBuffer.pos;
    return sendtoPixel;
}