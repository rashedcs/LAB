Img=imread('2.jpg');
%A = imnoise(Img,'Gaussian',0.04,0.003);
%Image with noise
subplot(1,2,1);
imshow(Img);
title('Original Image');
I = double(Img);

%Design the Gaussian Kernel
%Standard Deviation
sigma = 2.20;
%Window size
sz = 4;
[x,y]=meshgrid(-sz:sz,-sz:sz);

M = size(x,1)-1;
N = size(y,1)-1;
Exp_comp = -(x.^2+y.^2)/(2*sigma*sigma);
Kernel= exp(Exp_comp)/(2*pi*sigma*sigma);
%Initialize
Output=zeros(size(I));
%Pad the vector with zeros
I = padarray(I,[sz sz]);

%Convolution
for i = 1:size(I,1)-M
    for j =1:size(I,2)-N
        Temp = I(i:i+M,j:j+M).*Kernel;
        Output(i,j)=sum(Temp(:));
    end
end
%Image without Noise after Gaussian blur
Output = uint8(Output);
subplot(1,2,2);
imshow(Output);
title('After filter');






















%Read an Image
Img = imread('bby.jpg');

rgb  = zeros(size(Img,1),size(Img,2))
rgb = .298*Img(:,:,1)+.587*Img(:,:,2)+.114*Img(:,:,3)
subplot(3,1,1);
imshow(rgb),title('orginal image')

A = imnoise(rgb,'salt & pepper',0.02);

subplot(3,1,2);
imshow(A),title('noise image')
% %Image with noise
% figure(1),imshow(A);
% 
I = double(A);

%Design the Gaussian Kernel
%Standard Deviation
sigma = 1.76;
%Window size
sz = 4;
[x,y]=meshgrid(-sz:sz,-sz:sz);

M = size(x,1)-1;
N = size(y,1)-1;
Exp_comp = -(x.^2+y.^2)/(2*sigma*sigma);
Kernel= exp(Exp_comp)/(2*pi*sigma*sigma);


%Initialize
Output=zeros(size(I));
%Pad the vector with zeros
I = padarray(I,[sz sz]);

%Convolution
for i = 1:size(I,1)-M
    for j =1:size(I,2)-N
        Temp = I(i:i+M,j:j+M).*Kernel;
        Output(i,j)=sum(Temp(:));
    end
end
%Image without Noise after Gaussian blur
Output = uint8(Output);
subplot(3,1,3)
imshow(Output),title('filter image');

%figure(2),imshow(Output);


