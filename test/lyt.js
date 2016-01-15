//if
a=1;if(a>0){a=3;}else{a=0;}a==3;//√ true
console.log(a);
a=1;if(a>0)a=3;//√ a=3
console.log(a);
a=-1;if(a>0)a=3;else a=0;//√ a=0
console.log(a);
a=-1;if(a>0){a=3;}else{a=0;}a==0;//√ true
console.log(a);

//while
a=1;do a++;while(a<3);//√ a=3
console.log(a);
a=1;do{a++;}while(a<3);//√a=3 brace
console.log(a);
a=1;while(a<3)a++;//√ a=3
console.log(a);
a=2;while(a!=0)a--;//√ a=0
console.log(a);
a=2;while(a!=0)if(a==4)break;else a=4;//√ a=4 break success
console.log(a);
a=2;while(a!=0)if(a==2)break;else a=4;
console.log(a);
a=2;while(a!=0){a--;}//√a=0 brace
console.log(a);
a=10;while(true){a--;if(a==5)break;}//√a=5 break
console.log(a);
i=0;a=0;while(a<10){a++;if(a==12){continue;}i++};//√ i=9; continue
console.log(a);console.log(i);
i=0;a=0;while(a<10){a++;if(a==2){continue;}i++};//√ i=10;
console.log(a);console.log(i);

//switch
a=1;switch(a){case 1 : a=10;break;case 2: a=11;break;}//√a=10
console.log(a);console.log(i);
a=1;switch(a){case 1 : a=10;case 2: a=11;break;}//√a=11
console.log(a);console.log(i);
a=10;switch(a){default: a=10;case 1 : a++;case 2: a++;break;case 3: a=0;}//√a=12 no-default
console.log(a);console.log(i);
a=1;switch(a){case 1 : a++;default: a=10;case 2: a++;break;case 3: a=0;}//√a=11 in-default
console.log(a);console.log(i);
a=10;switch(a){case 1 : a++;default: a=20;case 2: a++;break;case 3: a=0;}//√a=21 in-default

//for 
a=2;i=0;for(;i<10;i++){a++;}//a=12
console.log(a);console.log(i);
a=2;i=0;for(;i<10;i++)a++;//√a=12
console.log(a);console.log(i);
a=2;for(i=0;i<10;i++)a++;//√a=12
console.log(a);console.log(i);
i=0;for(;;i++)if(i==5)break;//√i=5
console.log(a);console.log(i);
i=0;for(;i<5;)if(i==0)i=6;//√i=5
console.log(a);console.log(i);
i=0;for(;;)if(i!=6)i=6;else break;//i=6
console.log(a);console.log(i);
a=0;i=100;for(i=0;i<10;i++){a++;}
console.log(a);console.log(i);
a=0;i=100;for(i=0;i<10;i++){if(i==5)continue;a++;}//a=9
console.log(a);console.log(i);
num=0;outermost:for(i=0;i<10;i++){for(j=0;j<10;j++){if(i==5&&j==5){break outermost;}num++;}}console.log(num);
num=0;outermost:for(i=0;i<10;i++){for(j=0;j<10;j++){if(i==5&&j==5){continue outermost;}num++;}}console.log(num);

//try-catch
// a=0;try{throw 1;}catch(e){console.log(e);a++;};//√
// a=0;try{a=10;}catch(e){console.log(e);a++;};//√
// a=0;try{throw 1;}catch(e){a=10;}finally{a=20;};//√
// a=0;try{a=1;}catch(e){a=10;}finally{a=20;};//√
// a=0;try{return 1;}catch(e){a=10;}finally{a=20;}//√a=20
// a=0;try{throw 1;return 1;}catch(e){return 2;}finally{a=20;}//√a=20
// a=0;try{return 1;throw 1;}catch(e){return 2;}finally{return 3;}//√return 3
// a=0;try{throw 1;return 1;}catch(e){return 2;}finally{return 3;}//√return 3;



