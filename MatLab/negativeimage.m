%with function
im=imread('C:\Users\Rashed\Downloads\1.jpg');
subplot(3,1,1), imshow(im), title('orginal image');

[x y] = size(im);
for i=1:1:x
    for j=1:1:y
        im(i,j) = 255-im(i,j);
    end
end

subplot(3,1,2), imshow(im), title('Histogram');



%without function
im = imread('bby.jpg')

subplot(2,1,1)
imshow(im),title('orginal image')

rgb = zeros(size(im,1),size(im,2))
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3)

neg = 255- double(rgb)

s = uint8(neg)
subplot(2,1,2), imshow(s),title('negative image')
