img=imread('1.jpg');
subplot(1,2,1);

imshow(img);
title('Binary Input image');
%[x, y] = size(img);


for i = 1:size(img,1)
   for j = 1:size(img,2)
     % image(i,j)=0.2989*img(i,j,1)+0.5870*img(i,j,2)+0.1140*img(i,j,3);
     % standard value for gray image
     %image(i,j)=0.3*img(i,j,1)+0.6*img(i,j,2)+0.1*img(i,j,3);
     image(i,j)=0.40*img(i,j,1)+0.50*img(i,j,2)+0.30*img(i,j,3);
   end
end

subplot(1,2,2);
imshow(image);
title('Gray Scale  image');