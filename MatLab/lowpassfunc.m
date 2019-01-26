im = imread('download.jpg')
rgb  = zeros(size(im,1),size(im,2))
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3)
h = fspecial('motion', 5, 10);
c=imfilter(rgb,h);
subplot(2,1,1)
imshow(c),title('lowpass');

h = rgb-c;
subplot(2,1,2)
imshow(h),title('high pass filter')