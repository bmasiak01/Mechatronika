#include <stdio.h>
#include <math.h>
#include<stdlib.h>

float odleglosc(float x1,float x2, float y1, float y2);
float roznica(float r1, float r2);
float suma(float r1, float r2);
float punkty_przeciecia_p1(float x1,float y1, float r1, float x2, float y2, float r2);
float punkty_przeciecia_p2(float x1,float y1, float r1, float x2, float y2, float r2);
float punkty_przeciecia_q1(float x1,float y1, float r1, float x2, float y2, float r2);
float punkty_przeciecia_q2(float x1,float y1, float r1, float x2, float y2, float r2);

int main()
{
    float x1,x2,y1,y2,r1,r2;
//    char pytanie[] = "t";

//while(pytanie=="t")........Ta pêtla nie dzia³a, ale nie mia³em ju¿ czasu i si³, ¿eby patrzeæ na ten program
//{

    printf("Podaj wspolrzedne srodka pierwszego okregu (x1,y1)\n");
    scanf("%f %f",&x1 ,&y1);
    printf("Podaj promien tego okregu:\n");
    scanf("%f",&r1);

    printf("Podaj wspolrzedne srodka drugiego okregu (x2,y2)\n");
    scanf("%f %f",&x2 ,&y2);
    printf("Podaj promien tego okregu:\n");
    scanf("%f",&r2);

    if(odleglosc(x1,x2,y1,y2)>suma(r1,r2)) printf("Okregi rozlaczne zewnetrznie.\n");
    if(odleglosc(x1,x2,y1,y2)==suma(r1,r2))
    {
        printf("Okregi styczne zewnetrznie.\n");
        printf("Punkt stycznosci okregow to:( %f ,%f )",punkty_przeciecia_p1(x1,y1,r1,x2,y2,r2),punkty_przeciecia_p2(x1,y1,r1,x2,y2,r2));
    }
    if((odleglosc(x1,x2,y1,y2)>roznica(r1,r2))&&(odleglosc(x1,x2,y1,y2)<suma(r1,r2)))
    {

        printf("Okregi przecinaja sie.\n");
        printf("Punkty przciecia okregow to:( %f ,%f ) oraz ( %f , %f )",punkty_przeciecia_p1(x1,y1,r1,x2,y2,r2),punkty_przeciecia_p2(x1,y1,r1,x2,y2,r2)
               ,punkty_przeciecia_q1(x1,y1,r1,x2,y2,r2),punkty_przeciecia_q2(x1,y1,r1,x2,y2,r2));
    }
    if(odleglosc(x1,x2,y1,y2)==roznica(r1,r2))
    {
        if ((x1==x2)&&(y1==y2)) printf("Okregi identyczne.\n");
        else
        {
            printf("Okregi styczne wewnetrznie.\n");
            printf("Punkt stycznosci okregow to:( %f ,%f )",punkty_przeciecia_p1(x1,y1,r1,x2,y2,r2),punkty_przeciecia_p2(x1,y1,r1,x2,y2,r2));

        }
    }
    if(odleglosc(x1,x2,y1,y2)<roznica(r1,r2)) printf("Okregi rozlaczne wewnetrznie.\n");

//   printf("\n\nCzy chcesz kontynuowac? (t/n)");
//scanf("%c",pytanie);
//}


    return 0;
}

float odleglosc(float x1,float x2, float y1, float y2)
{
    float w;
    w=abs(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
    return w;
}

float roznica(float r1, float r2)
{
    float w;
    w=abs(r2-r1);
    return w;
}
float suma(float r1, float r2)
{
    float w;
    w=r2+r1;
    return w;
}

float punkty_przeciecia_p1 (float x1,float y1, float r1, float x2, float y2, float r2)
{
    float vx,vy,sin,cos,p1;
    cos = (odleglosc(x1,x2,y1,y2)*odleglosc(x1,x2,y1,y2) + r1*r1 - r2*r2) / (2*odleglosc(x1,x2,y1,y2)*r1);
    sin = sqrt(1-cos*cos);

        vx=(x2-x1)*r1/odleglosc(x1,x2,y1,y2);
        vy=(y2-y1)*r1/odleglosc(x1,x2,y1,y2);

    p1 = vx*cos - vy*sin + x1;

    return p1;
}
float punkty_przeciecia_p2 (float x1,float y1, float r1, float x2, float y2, float r2)
{
    float vx,vy,sin,cos,p2;
    cos = (odleglosc(x1,x2,y1,y2)*odleglosc(x1,x2,y1,y2) + r1*r1 - r2*r2) / (2*odleglosc(x1,x2,y1,y2)*r1);
    sin = sqrt(1-cos*cos);

        vx=(x2-x1)*r1/odleglosc(x1,x2,y1,y2);
        vy=(y2-y1)*r1/odleglosc(x1,x2,y1,y2);

    p2 = vx*sin + vy*cos + y1;

    return p2;
}
float punkty_przeciecia_q1 (float x1,float y1, float r1, float x2, float y2, float r2)
{
    float vx,vy,sin,cos,q1;
    cos = (odleglosc(x1,x2,y1,y2)*odleglosc(x1,x2,y1,y2) + r1*r1 - r2*r2) / (2*odleglosc(x1,x2,y1,y2)*r1);
    sin = sqrt(1-cos*cos);

        vx=(x2-x1)*r1/odleglosc(x1,x2,y1,y2);
        vy=(y2-y1)*r1/odleglosc(x1,x2,y1,y2);


    q1 = vx*cos + vy*sin + x1;


    return q1;
}
float punkty_przeciecia_q2 (float x1,float y1, float r1, float x2, float y2, float r2)
{
    float vx,vy,sin,cos,q2;
    cos = (odleglosc(x1,x2,y1,y2)*odleglosc(x1,x2,y1,y2) + r1*r1 - r2*r2) / (2*odleglosc(x1,x2,y1,y2)*r1);
    sin = sqrt(1-cos*cos);

        vx=(x2-x1)*r1/odleglosc(x1,x2,y1,y2);
        vy=(y2-y1)*r1/odleglosc(x1,x2,y1,y2);

    q2 = vy*cos - vx*sin + y1;

    return q2;
}
