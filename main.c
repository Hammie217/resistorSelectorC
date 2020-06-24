#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int E3[] = {10,22,47};
int E6[] = {10,15,22,33,47,68};
int E12[] = {10,12,15,18,22,27,33,39,47,56,68,82};
int E24[] = {10,11,12,13,15,16,18,20,22,24,27,30,33,36,39,43,47,51,56,62,68,75,82,91};
int E48[] = {100,105,110,115,121,127,133,140,147,178,187,196,154,162,169,205,215,226,237,249,261,274,287,301,316,332,348,365,383,402,422,442,464,487,511,536,562,590,619,649,681,715,750,787,825,866,909,953};
int E96[] = {100,102,105,107,110,113,115,118,121,124,127,130,133,137,140,143,147,150,154,158,162,165,169,174,178,182,187,191,196,200,205,210,216,221,226,232,237,243,249,255,261,267,274,280,287,294,301,309,316,324,332,340,348,357,365,374,383,392,402,412,422,432,442,453,464,475,487,499,511,523,536,549,562,576,590,604,619,634,649,665,681,698,715,732,750,768,787,806,825,845,866,887,909,931,953,976};

float modulo(float val){
    if(val>=0)
        return val;
    else
        return -val;
}

int main(int argc, char **argv){
  char *evalue = NULL;
  char *rvalue = NULL;
  int index;
  int c;

  opterr = 0;
  while ((c = getopt (argc, argv, "r:e:")) != -1)
    switch (c)
      {
      case 'r':
        rvalue = optarg;
        break;
      case 'e':
        evalue = optarg;
        break;
      case '?':
        if ((optopt == 'e')||(optopt == 'r'))
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  //printf ("aflag = %d, bflag = %d, evalue = %s, rvalue = %s\n",aflag, bflag, evalue, rvalue);

int foundError=0;
  for (index = optind; index < argc; index++){
    printf ("Non-option argument %s\n", argv[index]);
    foundError++;
  }
  if(foundError){
      return 1;
  }


    float inRatio;
    if(rvalue==NULL){
        printf("What's your desired resistor ratio (greater than 1) 1:...\n");
        scanf("%f", &inRatio);
    }
    else{
        inRatio = atof(rvalue);
    }
    if(inRatio<1){
        fprintf (stderr, "Value %f is too small.\n", inRatio);
        return 1;
    }
    
    int bottomRange = pow(10,floor(log10(floor(inRatio))));
    int topRange = pow(10,floor(log10(floor(inRatio/0.1))));
    int closestA=0;
    int closestB=0;
    int actualFound=0;
    float closestVal=1000;
    float tempClosest;

if(evalue==NULL)
    evalue=0;

    if((evalue==NULL)||(strcmp(evalue,"3")==0)){

    printf("E3:\n");
    for(float multiplier=bottomRange;multiplier<=topRange;multiplier*=10){
            for(int i=0;i<sizeof(E3) / sizeof(int);i++){
                for(int ii=0;ii<sizeof(E3) / sizeof(int);ii++){
                    float ratio =((float)E3[ii]/(float)E3[i])*multiplier;
                    if(ratio==inRatio){
                        printf("  %d:%d=%f\n",E3[ii]*(int)multiplier,E3[i],ratio);
                        actualFound=1;
                    }
                    else{
                        tempClosest = modulo(ratio-inRatio);
                        if(tempClosest<closestVal){
                            closestVal = tempClosest;
                            closestA = E3[ii]*(int)multiplier;
                            closestB = E3[i];
                        }
                    } 
                }
            }
        }
        if(actualFound==0){
            printf("  Closest: %d:%d =%f ≈%f\n",closestA,closestB,(float)closestA/(float)closestB,inRatio);
        }
        }


    if((evalue==NULL)||(strcmp(evalue,"6")==0)){
    printf("E6:\n");
    actualFound=0;
    closestVal=1000;
    for(float multiplier=bottomRange;multiplier<=topRange;multiplier*=10){
            for(int i=0;i<sizeof(E6) / sizeof(int);i++){
                for(int ii=0;ii<sizeof(E6) / sizeof(int);ii++){
                    float ratio =((float)E6[ii]/(float)E6[i])*multiplier;
                    if(ratio==inRatio){
                        printf("  %d:%d=%f\n",E6[ii]*(int)multiplier,E6[i],ratio);
                        actualFound=1;
                    }
                    else{
                        tempClosest = modulo(ratio-inRatio);
                        if(tempClosest<closestVal){
                            closestVal = tempClosest;
                            closestA = E6[ii]*(int)multiplier;
                            closestB = E6[i];
                        }
                    } 
                    
                }
            }
        }
        if(actualFound==0){
            printf("  Closest: %d:%d =%f ≈%f\n",closestA,closestB,(float)closestA/(float)closestB,inRatio);
        }
    }


    if((evalue==NULL)||(strcmp(evalue,"12")==0)){

    printf("E12:\n");
    actualFound=0;
    closestVal=1000;
    for(float multiplier=bottomRange;multiplier<=topRange;multiplier*=10){
            for(int i=0;i<sizeof(E12) / sizeof(int);i++){
                for(int ii=0;ii<sizeof(E12) / sizeof(int);ii++){
                    float ratio =((float)E12[ii]/(float)E12[i])*multiplier;
                    if(ratio==inRatio){
                        printf("  %d:%d=%f\n",E12[ii]*(int)multiplier,E12[i],ratio);
                        actualFound=1;
                    }
                    else{
                        tempClosest = modulo(ratio-inRatio);
                        if(tempClosest<closestVal){
                            closestVal = tempClosest;
                            closestA = E12[ii]*(int)multiplier;
                            closestB = E12[i];
                        }
                    } 
                    
                }
            }
        }
        if(actualFound==0){
            printf("  Closest: %d:%d =%f ≈%f\n",closestA,closestB,(float)closestA/(float)closestB,inRatio);
        }
            }


    if((evalue==NULL)||(strcmp(evalue,"24")==0)){

    printf("E24:\n");
    actualFound=0;
    closestVal=1000;
    for(float multiplier=bottomRange;multiplier<=topRange;multiplier*=10){
        for(int i=0;i<sizeof(E24) / sizeof(int);i++){
            for(int ii=0;ii<sizeof(E24) / sizeof(int);ii++){
                float ratio =((float)E24[ii]/(float)E24[i])*multiplier;
                if(ratio==inRatio){
                    printf("  %d:%d=%f\n",E24[ii]*(int)multiplier,E24[i],ratio);
                    actualFound=1;
                    }
                    else{
                        tempClosest = modulo(ratio-inRatio);
                        if(tempClosest<closestVal){
                            closestVal = tempClosest;
                            closestA = E24[ii]*(int)multiplier;
                            closestB = E24[i];
                        }
                    } 
                
            }
        }
    }
    if(actualFound==0){
            printf("  Closest: %d:%d =%f ≈%f\n",closestA,closestB,(float)closestA/(float)closestB,inRatio);
        }
            }


    if((evalue==NULL)||(strcmp(evalue,"48")==0)){

    printf("E48:\n");
    actualFound=0;
    closestVal=1000;
    for(float multiplier=bottomRange;multiplier<=topRange;multiplier*=10){
        for(int i=0;i<sizeof(E48) / sizeof(int);i++){
            for(int ii=0;ii<sizeof(E48) / sizeof(int);ii++){
                float ratio =((float)E48[ii]/(float)E48[i])*multiplier;
                if(ratio==inRatio){
                    printf("  %d:%d=%f\n",E48[ii]*(int)multiplier,E48[i],ratio);
                    actualFound=1;
                    }
                    else{
                        tempClosest = modulo(ratio-inRatio);
                        if(tempClosest<closestVal){
                            closestVal = tempClosest;
                            closestA = E48[ii]*(int)multiplier;
                            closestB = E48[i];
                        }
                    } 
                
            }
        }
    }
    if(actualFound==0){
            printf("  Closest: %d:%d =%f ≈%f\n",closestA,closestB,(float)closestA/(float)closestB,inRatio);
        }
    }

    if((evalue==NULL)||(strcmp(evalue,"96")==0)){
    printf("E96:\n");
    actualFound=0;
    closestVal=1000;
    for(float multiplier=bottomRange;multiplier<=topRange;multiplier*=10){
        for(int i=0;i<sizeof(E96) / sizeof(int);i++){
            for(int ii=0;ii<sizeof(E96) / sizeof(int);ii++){
                float ratio =((float)E96[ii]/(float)E96[i])*multiplier;
                if(ratio==inRatio){
                    printf("  %d:%d=%f\n",E96[ii]*(int)multiplier,E96[i],ratio);
                    actualFound=1;
                    }
                    else{
                        tempClosest = modulo(ratio-inRatio);
                        if(tempClosest<closestVal){
                            closestVal = tempClosest;
                            closestA = E96[ii]*(int)multiplier;
                            closestB = E96[i];
                        }
                    } 
                
            }
        }
    }
    if(actualFound==0){
            printf("  Closest: %d:%d =%f ≈%f\n",closestA,closestB,(float)closestA/(float)closestB,inRatio);
        }
            }

    

    


    return 0;

}