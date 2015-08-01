varying vec2 position;

float _sq(float x)
{
    return x * x;
}

void main(void)
{
    float DIM = 1024;
    int i = int((position.x + 1.) / 2. * DIM);
    int j = int((-position.y + 1.) / 2. * DIM);

    float w=sqrt(_sq(32-i%64)+_sq(32-j%64))/91,x=sqrt(_sq(i-512)+_sq(j-512))/724;
    int r = int(((2048-i-j)*w/2048*x-w*x+1)*255.);
    int g = int(((1024-i+j)*w/2048*x-w*x+1)*255.);
    int b = int(((1024+i-j)*w/2048*x-w*x+1)*255.);

    gl_FragColor.r = float(r % 256) / 256.;
    gl_FragColor.g = float(g % 256) / 256.;
    gl_FragColor.b = float(b % 256) / 256.;
}