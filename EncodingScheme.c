char* encode(char* input) {
    char *s="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/0123456789";
    int n=strlen(input);
    char *output=(char*)malloc(sizeof(char)*(n*4/3+3));
    //char* output;
    int index=0,len,i;
    for(i=0;i<n-2;i+=3)
    {
            len=3+i;
            output[index++]=s[input[len-3]>>2];
            output[index++]=s[((input[len-3]&0X03)<<4)|((input[len-2]&0XF0)>>4)];
            output[index++]=s[((input[len-2]&0X0F)<<2)|((input[len-1]&0XC0)>>6)];
            output[index++]=s[(input[len-1]&0X3F)];
    }
    if(n%3==2)
    {
         len=3+i;
         output[index++]=s[input[len-3]>>2];
         output[index++]=s[((input[len-3]&0X03)<<4)|((input[len-2]&0XF0)>>4)];
         output[index++]=s[((input[len-2]&0X0F)<<2)];
         output[index++]='=';
    }
    else if(n%3==1)
    {
         len=3+i;
         output[index++]=s[input[len-3]>>2];
         output[index++]=s[(input[len-3]&0X03)<<4];
         output[index++]='=';
         output[index++]='=';
    }
    output[index++]='\0';
    return output;
}