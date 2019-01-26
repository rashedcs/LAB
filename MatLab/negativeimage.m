im = imread('bby.jpg')

subplot(2,1,1)
imshow(im),title('orginal image')

rgb = zeros(size(im,1),size(im,2))
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3)

neg = 255- double(rgb)

s = uint8(neg)

subplot(2,1,2)
imshow(s),title('negative image')