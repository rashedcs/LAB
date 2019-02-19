%without buitt in  function
input=imread('test.jpg');
subplot(1,2,1), imshow(input), title('RGB Scale image');
[x,y,~] = size(input);
for i = 1:1:x
   for j = 1:1:y
      output(i,j) = 0.40*input(i,j,1) + 0.50*input(i,j,2) + 0.30*input(i,j,3);
   end
end
subplot(1,2,2), imshow(output), title('Gray Scale  image');


%with buitt in  function
i = imread('bby.jpg')

subplot(2,1,1);
imshow(i),title('orginal image')

rgb = zeros(size(i,1),size(i,2))

rgb = .298*i(:,:,1)+.587*i(:,:,2)+.114*i(:,:,3)

subplot(2,1,2)
imshow(rgb),title('RGB image')
