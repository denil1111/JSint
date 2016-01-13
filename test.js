//if
a=1;if(a>0){a=3;}else{a=0;}a==3;//true
a=1;if(a>0)a=3;//√ a=3
a=-1;if(a>0)a=3;else a=0;//√ a=0
a=-1;if(a>0){a=3;}else{a=0;}a==0;//true

//while
a=1;do a++;while(a<3);//√ a=3
a=1;do{a++;}while(a<3);//a=3 brace
a=1;while(a<3)a++;//√ a=3
a=2;while(a!=0)a--;//√ a=0
a=2;while(a!=0)if(a==4)break;else a=4;//√ a=4 break success
a=2;while(a!=0)if(a==2)break;else a=4;
//i=0;a=0;while(a<10)if(a==2)continue;else i++;
a=2;while(a!=0){a--;}//a=0 brace
a=10;while(true){a--;if(a==5)break;}//a=5 break

//switch
a=1;switch(a){case 1 : a=10;break;case 2: a=11;break;}//√a=10
a=1;switch(a){case 1 : a=10;case 2: a=11;break;}//√a=11
a=10;switch(a){default: a=10;case 1 : a++;case 2: a++;break;case 3: a=0;}//√a=12 no-default
a=1;switch(a){case 1 : a++;default: a=10;case 2: a++;break;case 3: a=0;}//√a=11 in-default
a=10;switch(a){case 1 : a++;default: a=20;case 2: a++;break;case 3: a=0;}//√a=21 in-default

//for 
a=2;i=0;for(;i<10;i++){a++;}//a=12
a=2;i=0;for(;i<10;i++)a++;//√a=12
a=2;for(i=0;i<10;i++)a++;//a=12
i=0;for(;;i++)if(i==5)break;//i=5
a=2;i=0;for(;i<10;i++)a++;//a=11
i=0;for(;i<5;)if(i==0)i=6;//i=5
i=0;for(;;)if(i!=6)i=6;else break;//i=6
//a=0;for(i=0;i<10;i++)if(i==5)continue;a++;//a=11