#include <stdio.h>

int main(int argc, char *argv[]){


    // 입력값이 두개인지 검사
    // (./프로그램명 파일위치/파일명.확장자   최종:프로그램명(INDEX[0]), 검사할 파일명(INDEX[1]))
    if (argc != 2){
        return 1;
    }
    // 파일열어서 파일명(두번째인자) 주소값받아봄.
    FILE *file = fopen(argv[1],"r");
    if (file == NULL){      //fopen()은 파일불러오는데오류생기면 null반환함.
        return 1;       //오류생길시, 리턴값 반환.
    }

    unsigned char bytes[3];     //unsigned: -128~127범위의 값을 0~255로 표현하기위해.
    fread(bytes, 3, 1, file);   //fread(파일내에서읽을 배열, 3바이트까지, 1번읽음, 읽을파일)
    if (bytes[0]==0xff && bytes[1]==0xd8 && bytes[2]==0xff){  //JPEG주소상의 표기 약속(ff && d8 && ff 순서)
        printf("아마 JPEG\n");
    }else{
        printf("아냐 JPEG");
    }
}
