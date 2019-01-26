a= imread('download.jpg');

b  = zeros(size(a,1),size(a,2))
b = .298*a(:,:,1)+.587*a(:,:,2)+.114*a(:,:,3)
%b= rgb2gray(a);
subplot(3,1,1),imshow(b),title('Input image');

h=[-1 -1 -1; 2 2 2; -1 -1 -1];

w = wextend(2,'zpd',b,1);
[r,c] = size(w);

for i=1:1:r-2,
    for j=1:1:c-2
        e = w(i:i+2,j:j+2);
        m = h.*double(e);
        sm = sum(m);
        rs = sm(1,1)+sm(1,2)+sm(1,3);
        avg = rs/9;
        outim(i,j) = avg;
    end
end

out = uint8(outim);

subplot(3,1,2)
imshow(out),title('horizontally detected');


w = wextend(2,'zpd',b,1);
[r,c] = size(w);
h = [-1 2 -1; -1 2 -1; -1 2 -1];

for i=1:1:r-2,
    for j=1:1:c-2
        e = w(i:i+2,j:j+2);
        m = h.*double(e);
        sm = sum(m);
        rs = sm(1,1)+sm(1,2)+sm(1,3);
        avg = rs/9;
        outim(i,j) = avg;
    end
end

out = uint8(outim);

subplot(3,1,3)
imshow(out),title('vertically detected');


% c=imfilter(b,h);
% subplot(3,1,2),imshow(c),title('Horizontal detected image');
% 
% i=[-1 2 -1; -1 2 -1; -1 2 -1];
% d = imfilter(b,i);
% subplot(3,1,3),imshow(d),title('Vertical detected image2');