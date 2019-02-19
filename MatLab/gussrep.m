im = imread('tarek.jpg')

rgb = zeros(size(im,1),size(im,2));
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3);
subplot(3,1,1)
imshow(rgb),title('orginal image')

A = imnoise(rgb,'salt & pepper',0.02);
subplot(3,1,2)
imshow(A),title('noise image')

I = double(A);
sz = 4;
sigma = 1.76;

[x,y] = meshgrid(-sz:sz,-sz:sz);

M = size(x,1)-1;
N = size(y,1)-1;

ex = -(x.^2+y.^2)/(2*sigma*sigma);
kernel = exp(ex)/(2*pi*sigma*sigma);

outim = zeros(size(I));
I = padarray(I,[sz sz]);

for i=1:size(I,1)-M
    for j=1:size(I,2)-N
        temp = I(i:i+M,j:j+M).*kernel;
        outim(i,j) = sum(temp(:));
    end
end

out = uint8(outim);

subplot(3,1,3)
imshow(out),title('filter image');


%without function
%Gaussian filter using MATLAB built_in function
%Read an Image
Img = imread('tarek.jpg');
A = imnoise(Img,'Gaussian',0.04,0.003);
%Image with noise
figure(1),imshow(A);

H = fspecial('Gaussian',[9 9],1.76);
GaussF = imfilter(A,H);
figure(2),imshow(GaussF);
