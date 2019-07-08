
x=[1 2 3 4 0 0 0];
y=[1 1 1 1 0 0 0];
dxSize=4;
dySize=4;
dx=0;
dy=0;
dz=dxSize+dySize-1;
dzstart=dx+dy;
dzend=dzstart+dxSize+dySize-2;
b=zeros(dz,1);
display(b);

for i=1:1:dz
    temp=i;
    for j=1:1:i     
        b(i)=b(i)+(x(j)*y(temp));
        temp=temp-1;
    end
end
%z=conv(x,y);
display(b);
dtz=[dzstart:dzend];
stem(dtz,b);