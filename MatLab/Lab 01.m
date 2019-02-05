a=imread ('habu.jpg');
b=imread ('babu.jpg');


%Image with by default function
b = imresize (a, [400,400]);
d = imresize (c, [400,400]);
r = imadd(b, d); 
subplot(3,1,1), imshow(r),title('image add func');


%Image with custom function
k = imresize(b, [size(a,1),size(a,2)]);
[x, y] = size(k) %height and wedth of 1st image

for i = 1: x
   for j = 1: y
          im3(i, j) = b(i, j) + d(i, j);
   end
end
subplot(3,1,2), imshow(im3),title('image add no func');
