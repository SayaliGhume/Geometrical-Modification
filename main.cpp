#include <stdio.h>#include <iostream>#include <stdlib.h>
#include<math.h>
using namespace std;


int main()
{
        FILE *file;

	// Allocate image data array
	unsigned char Imagedata_warp[300][300][3],Imagedata_warp_op1[300][300][3];

	 // Read image (filename specified by first argument) into image data matrix	if (!(file=fopen("dog.raw","rb"))) {		cout << "Cannot open file: " << "Kitten_1.raw" <<endl;		exit(1);	}	fread(Imagedata_warp, sizeof(unsigned char), 300*300*3, file);	fclose(file);

	//assign all pixels black value

	for(int i=0;i<300;i++)
    {
        for(int j=0;j<300;j++)
        {
            for(int m=0;m<3;m++)
            {
                 Imagedata_warp_op1[i][j][m]=0;
            }

        }
    }

    //declare variables used for bilinear interpolation
    float u,v,u_del,v_del;
    int u11,v11;
    int A0_r,B0_r,C0_r,D0_r,A0_g,B0_g,C0_g,D0_g,A0_b,B0_b,C0_b,D0_b;


    //loop to scan the entire image
    for(int i=0;i<300;i++)
    {
        for(int j=0;j<300;j++)
        {
            //conditions for triangle 1
            if(j>=i && j<=150 && i<=150)
            {
                //finding pixels of source image using inverse transform matrix
                u=i+j-150;
                v=2*j-150;


                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {
                           //rounding off (ratio is 1)
                    u11=floor(u);
                    v11=floor(v);

                            //finding residue
                        u_del=u-u11;

                        v_del=v-v11;


                //finding four neighbouring pixels

                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                    //interpolating neighbouring pixels
                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);

                       }

                       }
                //condition for tirangle 2
                else if(i+j-300<=0 && j>=150 && i<=150)
                {
                     u=i-j+150;
                    v=2*j-150;


                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {

                            u11=floor(u);
                            v11=floor(v);

                            u_del=u-u11;

                            v_del=v-v11;



                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);


                }

            }

            //condition for triangle 3
            else if(j<=i && i<=150 && j<=150)
            {
                 u=2*i-150;
                v=i+j-150;


                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {



                    u11=floor(u);
                    v11=floor(v);


                        u_del=u-u11;

                        v_del=v-v11;



                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);

                       }
            }

            //condition for traingle 4
           else if(i+j-300>=0 && i<=150 && j>=150)
                {


                u=2*i-150;
                v=-i+j+150;


                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {


                   //row ratio=col ratio=1;
                    u11=floor(u);
                    v11=floor(v);

                        u_del=u-u11;

                        v_del=v-v11;




                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);

                       }

                }

                //condition for triangle 5
                else if(i+j-300<=0 && i>=150 && j<=150){


                u=2*i-150;
                v=-i+j+150;


                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {


                   //row ratio=col ratio=1;
                    u11=floor(u);
                    v11=floor(v);

                        u_del=u-u11;

                        v_del=v-v11;




                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);

                       }

                }

                //condition for triangle 6
                else if(i+j-300>=0 && i>=150 && j<=150){


                u=i-j+150;
                v=2*j-150;

                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {


                   //row ratio=col ratio=1;
                    u11=floor(u);
                    v11=floor(v);

                        u_del=u-u11;

                        v_del=v-v11;




                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);

                       }

                }

                //condition for triangle 7
                else if(j<=i && j>=150 && i>=150){


                u=i+j-150;
                v=2*j-150;


                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {

                    u11=floor(u);
                    v11=floor(v);


                        u_del=u-u11;

                        v_del=v-v11;




                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);

                       }

                }

                //condition for triangle 8
                else if(j>=i && j>=150 && i>=150){


                u=2*i-150;
                v=i+j-150;


                    if(u>=0 && u<=299 && v>=0 && v<=299)
                       {



                    u11=floor(u);
                    v11=floor(v);


                        u_del=u-u11;

                        v_del=v-v11;



                A0_r=Imagedata_warp[u11][v11][0];
                B0_r=Imagedata_warp[u11][v11+1][0];
                C0_r=Imagedata_warp[u11+1][v11][0];
                D0_r=Imagedata_warp[u11+1][v11+1][0];

                Imagedata_warp_op1[i][j][0]=A0_r*(1-u_del)*(1-v_del)+B0_r*(u_del)*(1-v_del)+C0_r*(1-u_del)*(v_del)+D0_r*(u_del)*(v_del);


                A0_g=Imagedata_warp[u11][v11][1];
                B0_g=Imagedata_warp[u11][v11+1][1];
                C0_g=Imagedata_warp[u11+1][v11][1];
                D0_g=Imagedata_warp[u11+1][v11+1][1];

                Imagedata_warp_op1[i][j][1]=A0_g*(1-u_del)*(1-v_del)+B0_g*(u_del)*(1-v_del)+C0_g*(1-u_del)*(v_del)+D0_g*(u_del)*(v_del);



                A0_b=Imagedata_warp[u11][v11][2];
                B0_b=Imagedata_warp[u11][v11+1][2];
                C0_b=Imagedata_warp[u11+1][v11][2];
                D0_b=Imagedata_warp[u11+1][v11+1][2];

                Imagedata_warp_op1[i][j][2]=A0_b*(1-u_del)*(1-v_del)+B0_b*(u_del)*(1-v_del)+C0_b*(1-u_del)*(v_del)+D0_b*(u_del)*(v_del);

                       }

                }


        }
    }


         if (!(file=fopen("Imagedata_dog_warpop.raw","wb"))) {		cout << "Cannot open file: " << "Imagedata_warpop1.raw" << endl;		exit(1);	}	fwrite(Imagedata_warp_op1, sizeof(unsigned char), 300*300*3, file);	fclose(file);

	return 0;

}
