i = imread('bby.jpg')

subplot(2,1,1);
imshow(i),title('orginal image')

rgb = zeros(size(i,1),size(i,2))

rgb = .298*i(:,:,1)+.587*i(:,:,2)+.114*i(:,:,3)

subplot(2,1,2)
imshow(rgb),title('RGB image')