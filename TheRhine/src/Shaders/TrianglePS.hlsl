struct OUTPUT
{
    float4 pos : SV_POSITION;
    float4 col : COLOR;
};

float4 main(OUTPUT display) : SV_TARGET
{
    return display.col;
}