img=imread('C:\Users\Rashed\Downloads\1.jpg');
subplot(1,2,1), imshow(img), title('Binary Input image');
[x,y,z] = size(img);

for i = 1:1:x
   for j = 1:1:y
      res(i,j) = 0.40*img(i,j,1) + 0.50*img(i,j,2) + 0.30*img(i,j,3);
   end
end

subplot(1,2,2), imshow(res), title('Gray Scale  image');


%with function
i = imread('bby.jpg')

subplot(2,1,1);
imshow(i),title('orginal image')

rgb = zeros(size(i,1),size(i,2))

rgb = .298*i(:,:,1)+.587*i(:,:,2)+.114*i(:,:,3)

subplot(2,1,2)
imshow(rgb),title('RGB image')
