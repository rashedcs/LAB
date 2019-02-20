img=imresize(imread('C:\Users\Rashed\Downloads\1.jpg'),[200 200]);
%img=imresize(rgb2gray(imread('C:\Users\Rashed\Downloads\1.jpg')),[200 200]);
%img=rgb2gray(img); 
[x, y] = size(img); 
  
% Create a frequency array of size 256 
frequency = 1 : 256; 
count = 0; 
% Iterate over grayscale image matrix for every possible intensity value 
% and count them 
    
for i = 1 : 256 
    for j = 1 : x 
        for k = 1 : y 
            % if image pixel value at location (j, k) is i-1 
            % then increment count 
            if img(j, k) == i-1 
                    count = count + 1;                     
            end
        end
    end
    % update ith position of frequency array with count 
    frequency(i) = count/x*y; 
  
    % reset count 
    count = 0; 
  
end

% Display Histogram 
n = 0:255
stem(n, frequency,'r '); 

%grid on; 
xlabel('Intensity Levels  -->'); 
ylabel('Number of pixels with such intensity levels -->'); 
title('HISTOGRAM OF THE IMAGE'); 


figure,
bar(n, frequency,'r '),title('Histogram')
%x = 1900:20:2000;
%y = [75 91 105 123.5 125 236];
%bar(x,y)

%figure
%x = 0:50:300
%y = frequency;
%bar(x,y)
