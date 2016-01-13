//if
a=1;if(a>0){a=3;}else{a=0;}a==3;//true
a=1;if(a>0)a=3;//√ a=3
a=-1;if(a>0)a=3;else a=0;//√ a=0
a=-1;if(a>0){a=3;}else{a=0;}a==0;//true

//while
a=1;do a++;while(a<3);//√ a=3
a=1;do{a++;}while(a<3);//a=3
a=1;while(a<3)a++;//√ a=3

//switch
a=1;switch(a){case 1 : a=10;break;case 2: a=11;break;}//√a=10
a=1;switch(a){case 1 : a=10;case 2: a=11;break;}//√a=11
a=10;switch(a){default: a=10;case 1 : a++;case 2: a++;break;case 3: a=0;}//√a=12 no-default
a=1;switch(a){case 1 : a++;default: a=10;case 2: a++;break;case 3: a=0;}//√a=11 in-default
a=10;switch(a){case 1 : a++;default: a=20;case 2: a++;break;case 3: a=0;}//√a=21 in-default
