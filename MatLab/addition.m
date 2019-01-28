D=imread('1.jpg');
figure,imshow(D);
E=imread('2.jpg');
figure,imshow(E);
 D=imresize(D,[size(E,1) size(E,2)]);
 A=double(E);
 C=uint8(zeros(size(A)));
 F=E;
[x,y]=find((A(:,:,1)+A(:,:,2)+A(:,:,3))>650);

 for i=1:size(x,1)
    C(x(i),y(i),:)=1; 
    F(x(i),y(i),:)=0;    
 end
 C=C.*D;
 C=C+F;
 figure,imshow(C);