%image=imresize(rgb2gray(imread('D:\Programming\Image Processing\Image\neg.jpg')),[200 200]);
%f=imresize(rgb2gray(imread('C:\Users\Rashed\Downloads\1.jpg')),[200 200]);
%h=imhist(f, 25);
%horz=linspace( 0, 255, 25);
%figure, bar(horz, h), axis([0 255 0 400]);

img=imread('C:\Users\Rashed\Downloads\1.jpg');
% Convert image to grayscale image  
img=rgb2gray(img); 
  
% get the dimension of the image  
[x, y] = size(img); 
  
  
% Create a frequency array of size 256 
frequency = 1 : 256; 
  
count = 0; 
  fon=0;
% Iterate over grayscale image matrix  
% for every possible intensity value 
% and count them 
    
for i = 1 : 256 
    for j = 1 : x 
        for k = 1 : y 
  
            % if image pixel value at location (j, k) is i-1 
            % then increment count 
            if img(j, k) == i-1 
                    count = count + 1; 
                    fon = fon + 1;
                    
            end
        end
    end
    % update ith position of frequency array with count 
    frequency(i) = count; 
  
    % reset count 
    count = 0; 
  
end
display(fon);
  
% Display Histogram 
n = 0:255
stem(n, frequency); 

grid on; 
ylabel('Number of pixels with such intensity levels -->'); 
xlabel('Intensity Levels  -->'); 
title('HISTOGRAM OF THE IMAGE'); 


x = 1900:20:2000;
y = [75 91 105 123.5 125 236];
bar(x,y)

%figure
%x = 0:50:300
%y = frequency;
%bar(x,y)
