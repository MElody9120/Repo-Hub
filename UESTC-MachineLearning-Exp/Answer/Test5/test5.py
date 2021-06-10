import numpy
import math
def DataBase():
 DataList = [['青绿', '蜷缩', '浊响', '清晰', '凹陷', '硬滑'], # 1
 ['乌黑', '蜷缩', '沉闷', '清晰', '凹陷', '硬滑'], # 2
 ['乌黑', '蜷缩', '浊响', '清晰', '凹陷', '硬滑'], # 3
 ['青绿', '蜷缩', '沉闷', '清晰', '凹陷', '硬滑'], # 4
 ['浅白', '蜷缩', '浊响', '清晰', '凹陷', '硬滑'], # 5
 ['青绿', '稍蜷', '浊响', '清晰', '稍凹', '软粘'], # 6
 ['乌黑', '稍蜷', '浊响', '稍糊', '稍凹', '软粘'], # 7
 ['乌黑', '稍蜷', '浊响', '清晰', '稍凹', '硬滑'], # 8
 ## 上为正例，下为负例
 ['乌黑', '稍蜷', '沉闷', '稍糊', '稍凹', '硬滑'], # 9
 ['青绿', '硬挺', '清脆', '清晰', '平坦', '软粘'], # 10
 ['浅白', '硬挺', '清脆', '模糊', '平坦', '硬滑'], # 11
 ['浅白', '蜷缩', '浊响', '模糊', '平坦', '软粘'], # 12
 ['青绿', '稍蜷', '浊响', '稍糊', '凹陷', '硬滑'], # 13
 ['浅白', '稍蜷', '沉闷', '稍糊', '凹陷', '硬滑'], # 14
 ['乌黑', '稍蜷', '浊响', '清晰', '稍凹', '软粘'], # 15
 ['浅白', '蜷缩', '浊响', '模糊', '平坦', '硬滑'] # 16
 ]
 classVector = [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, ]
 return DataList, classVector
def createVocabularyList(data):
 """
 获取所有单词的集合
 data: 数据集
 return: 所有单词的集合(即不含重复元素的单词列表)
 """
 vocabSet = set([]) # 创造空集
 for document in data:
    vocabSet = vocabSet | set(document) # "|"为求并集运算
 return list(vocabSet)
def find(vocabList, inputSet):
 """
 遍历查看该单词是否出现，出现该单词则将该单词置 1
 vocabList: 所有单词集合列表
 inputSet: 输入数据集
 :return: 匹配列表[0,1,0,1...]，其中 1 与 0 表示词汇表中的单词
是否出现在输入的数据集中
 """
 # 创建一个和词汇表等长的向量，并将其元素都设置为 0
 returnVector = [0] * len(vocabList)
 # 利用 index 方法检查文档中的所有单词，如果出现词汇表中匹配的单词，则置 1
 for word in inputSet:
    returnVector[vocabList.index(word)] = returnVector[vocabList.index(word)] + 1
 return returnVector
def trainNBO(trainMatrix, trainCategory):
 numTrainDocs = len(trainMatrix)
 numWords = len(trainMatrix[0])
 # 计算 p(坏瓜)的概率
 pAbusive = sum(trainCategory) / float(numTrainDocs)
 # 为了防止一个概率为 0，假设都有一个
 p0Num = numpy.ones(numWords)
 p1Num = numpy.ones(numWords)
 p0Denom = 2.0
 p1Denom = 2.0
 for i in range(numTrainDocs):
    if trainCategory[i] == 1:
        p1Num += trainMatrix[i]
        p1Denom += sum(trainMatrix[i])
 else:
    p0Num += trainMatrix[i]
    p0Denom += sum(trainMatrix[i])
    p1Vect = numpy.log((p1Num / p1Denom))
    p0Vect = numpy.log(p0Num / p0Denom)
 return p0Vect, p1Vect, pAbusive
##完成朴素贝叶斯分类 正例 1 负例 0
def classifyNB(vec2Classify, p0Vec, p1Vec, pClass1):
 p1 = sum(vec2Classify * p1Vec) + math.log(pClass1)
 p0 = sum(vec2Classify * p0Vec) + math.log(1.0 - pClass1)
 if p1 > p0:
     str = "正例"
     return str
 else:
    str = "负例"
 return str
def testNB():
 listOPosts, ListClasses = DataBase()
 myVocabList = createVocabularyList(listOPosts)
 trainMat = []
 for postinDoc in listOPosts:
    trainMat.append(find(myVocabList, postinDoc))
    p0V, p1V, pAb = trainNBO(trainMat, ListClasses)
    testEntry = ['青绿', '蜷缩', '沉闷', '稍糊', '稍凹', '硬滑']
 # testEntry =['浅白', '蜷缩', '浊响', '模糊', '平坦', '硬滑'] 此为 0 即负例
 thisDoc = numpy.array(find(myVocabList, testEntry))
 print(testEntry, '测试样本被朴素贝叶斯分类为', classifyNB(thisDoc,
p0V, p1V, pAb))
if __name__ == "__main__":
 listOPosts, listClasses = DataBase()
 vocabList = createVocabularyList(listOPosts)
 print(vocabList)
 trainMartix = []
 for postinDoc in listOPosts:
    trainMartix.append(find(vocabList, postinDoc))
 for i in trainMartix:
    print(i)
p0v, p1v, pav = trainNBO(trainMartix, listClasses)
print(p0v)
print(p1v)
print("坏瓜概率为" + str(pav * 100) + "%") # 即坏瓜概率
testNB()