# AST

ast -> abstract syntax tree  


![스크린샷 2022-06-09 오후 3 00 11](https://user-images.githubusercontent.com/76278794/172775253-50404a80-4e3d-4e5e-8a82-390871dd54a9.png)  

readline 라이브러리를 통해 사용자의 input을 입력받는다.  

프로그래밍 로직 상에서,  

Text -> Lexer(token화) -> Parser -> AST -> Evaluator -> Behavior  

이 방식대로 작동하게된다.  

Lexer는 텍스트를 각 토큰으로 분해한다.  
우리의 미니쉘 코드에서는 이 작업을 `Tokenizer`와 `Lexer`가 분담한다.  


Tokenizer 모듈이 텍스트의 각 1바이트를 잘라서 토큰화를 하게된다.  

```sh
echo "test | test" > result

token_buf
{
	{
		value : 'e'
		type : NORM
	},
	{
		value : 'c'
		type : NORM
	},
	{
		...
	}
	{
		value : '\"'
		type : DQOU
	},
	{
		value : 't'
		type : NORM
	}
	...
}
```

이렇게 1바이트별로 토큰화를 수행할때, 토큰화를 진행중인 문자가  
쌍 따옴표 내부에 있는지, 홑 따옴표 내부에 있는지, 아니면 이 둘 바깥에 있는지에 따라 type을 달리하게된다.  


<br>

이렇게 토큰화가 완료되면, `lexer`가 각 토큰을 이어붙이게된다.  
각 토큰을 이어붙이고 난 다음에는, 각 단어가 어느 위치에 있는지에 따라  
`word_type`을 정하게 된다.  




토큰화된 리스트를 parser 함수에서 구문분석하고 각 유효성을 검사하게된다.  
parser는 또한, 토큰화된 문자열을 AST로 변환하는 역할을 한다.  

이후, AST에서 구문 분석된 문장을 각 노드에 지니고있게된다.  


![스크린샷 2022-06-09 오후 3 05 12](https://user-images.githubusercontent.com/76278794/172776006-41f46e7c-d551-493e-bbc7-343d07cfbd72.png)  




# 트리 자료구조


