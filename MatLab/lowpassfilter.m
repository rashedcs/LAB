im = imread('babu.jpg')
%rgb  = zeros(size(im,1),size(im,2))
%rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3);
%subplot(2,1,1), imshow(rgb),title('Orginal image');
inim = rgb2gray(im);
subplot(2,1,1), imshow(inim),title('Input image')

exim = wextend(2,'zpd',rgb,1);
mask = [1 1 1 ; 1 1 1 ; 1 1 1];
[r,c] = size(w);

for i = 1:1:r-2
    for j = 1:1:c-2
        subim = exim(i:i+2, j:j+2);
        m = mask.*double(subim);
        cm = sum(m);
        rs = sm(1,1) + sm(1,2) + sm(1,3);
        avg = rs/9;
        outim(i,j) = avg;
    end
end

%outim = uint8(outim)
subplot(2,1,2), imshow(out), title('lowpass filter image');
