a = imread('download.jpg'); 
g=im2bw(a);
se=[0 1 0; 1 1 1; 0 1 0];    
%se=ones(6,1);   
b=imdilate(g,se);              		
subplot(1,2,1), imshow(g);title('input image');         		
subplot(1,2,2), imshow(b);   title('dilated image');    