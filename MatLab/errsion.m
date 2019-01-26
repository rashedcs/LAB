A=imread('circles.png');


subplot(3,1,1)
imshow(A),title('orginal image');


%Structuring element
B=getnhood(strel('disk',11));
%B=ones(6,1);  
B = double(B);
m=floor(size(B,1)/2);
n=floor(size(B,2)/2);
%Pad array on all the sides
C=padarray(A,[m n],1);
%Intialize a matrix with size of matrix A
D=false(size(A));
for i=1:size(C,1)-(2*m)
    for j=1:size(C,2)-(2*n)
       
        Temp=C(i:i+(2*m),j:j+(2*n));
        Temp = double(Temp);
        D(i,j)=min(min(Temp-B));
      
    end
end

subplot(3,1,2)
imshow(~D),title('errsion image');

oe=imerode(A,B);
subplot(3,1,3)
imshow(oe),title('errsion in function image');


