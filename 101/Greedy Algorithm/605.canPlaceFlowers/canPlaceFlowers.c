
#define TRUE 1
#define FALSE 0
#define bool int

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int result = FALSE;
    int fp = 0;
    int emptyPlace = 0;
    int occupyPlace = 0;
    for(int i=0;i<flowerbedSize;i++){
        if(flowerbed[i] == 0){
            emptyPlace++;
        }else{
            occupyPlace++;
            if(occupyPlace == 0){
                if(emptyPlace>=3 && emptyPlace%2!=0){
                    fp = emptyPlace/2 ;
                }
            }else if(occupyPlace == 1){

            }else{

            }
            
            emptyPlace = 0;
        }
    }
    if(fp>=n){
        result = TRUE;
    }
    return result;
}