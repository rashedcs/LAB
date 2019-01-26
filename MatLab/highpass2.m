im = imread('download.jpg')
rgb  = zeros(size(im,1),size(im,2))
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3)
subplot(2,1,1)
imshow(rgb),title('orginal image')

w = wextend(2,'zpd',rgb,1)
mask = [1 1 1 ; 1 1 1 ; 1 1 1]
[r,c] = size(w);

for i=1:1:r-2
    for j=1:1:c-2
        s = w(i:i+2,j:j+2);
        m = mask.*double(s);
        sm = sum(m);
        rs = sm(1,1)+sm(1,2)+sm(1,3);
        avg = rs/9;
        outim(i,j) = avg;
    end
end

subplot(2,1,2)
out = uint8(outim);
ou = rgb-out;
imshow(ou),title('highpass filter image')