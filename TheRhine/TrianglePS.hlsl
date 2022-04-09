struct OUTPUT
{
    float2 finalPos : SV_Position;
};

float4 main(OUTPUT fromvertexBuffer) : SV_TARGET
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);
}