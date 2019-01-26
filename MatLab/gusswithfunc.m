%Gaussian filter using MATLAB built_in function
%Read an Image
Img = imread('tarek.jpg');
A = imnoise(Img,'Gaussian',0.04,0.003);
%Image with noise
figure(1),imshow(A);

H = fspecial('Gaussian',[9 9],1.76);
GaussF = imfilter(A,H);
figure(2),imshow(GaussF);