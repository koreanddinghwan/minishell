# AST

ast -> abstract syntax tree  

![스크린샷 2022-06-09 오후 3 00 11](https://user-images.githubusercontent.com/76278794/172775253-50404a80-4e3d-4e5e-8a82-390871dd54a9.png)  

readline 라이브러리를 통해 사용자의 input을 입력받는다.  
이를 tokenizer 함수가 각 문자가 어떤 문자인지 파악하고, 토큰화한다.  
토큰화된 리스트를 parser 함수에서 구문분석하고 각 유효성을 검사하게된다.  
parser는 또한, 토큰화된 문자열을 AST로 변환하는 역할을 한다.  

이후, AST에서 구문 분석된 문장을 각 노드에 지니고있게된다.  


![스크린샷 2022-06-09 오후 3 05 12](https://user-images.githubusercontent.com/76278794/172776006-41f46e7c-d551-493e-bbc7-343d07cfbd72.png)  




# 트리 자료구조


