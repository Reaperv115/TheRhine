#pragma pack_matrix(row_major)

struct INPUT_VERTEX
{
    float2 coordinate : POSITION;
};

struct OUTPUT_VERTEX
{
    float2 newCoordinate : SV_Position;
};

OUTPUT_VERTEX main( INPUT_VERTEX intoBuffer)
{
    OUTPUT_VERTEX toRasterizer = (OUTPUT_VERTEX) 0;
    toRasterizer.newCoordinate = intoBuffer.coordinate;
	return toRasterizer;
}