- 채점에 사용되는 데이터는 sapiens.txt입니다. 각 폴더에 들어있는 sapiens.txt는 디버깅과 예제 작성을 위한 별도의 소형 파일입니다.

- 파일 경로는 "/NESPA/sapiens.txt"로 설정해주셔야 합니다.
  C : FILE *in=fopen("/NESPA/sapiens.txt","w");
  C++ : ifstream in("/NESPA/sapiens.txt");
  Python : open("/NESPA/sapiens.txt","w")

- 각 폴더에는 서로 다른 FASTA 형식의 sapiens.txt에 대한 예시가 들어있습니다.

- sapiens.txt를 읽을 때, 첫 줄의 아래 입력은 오류가 아닌 모든 FASTA 파일에 포함된 형식이므로 첫 줄 입력을 scanf나 input 등의 라인 입력을 사용해서 무시하고 두번째 줄 데이터부터 DNA 구성을 읽어들인다고 생각하시면 됩니다.
>gi|224384768|gb|CM000663.1| Homo sapiens chromosome 1, GRCh37 primary reference assembly

* sapiens_example
length : 18

* sapiens_small
length : 718

* sapiens
length : 1,100,960
A : 276838
G : 274505
T : 271070
C : 278547