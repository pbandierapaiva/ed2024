

class LCirc( list ):
	def __init__(self):
		list.__init__(self)
		self.corrente=0	    
	def __iter__(self):
		return self
	def __next__(self):
		if len(self)==0:
			return None
		
		retorno = self[self.corrente]
		
		if self.corrente==(len(self)-1): # verifica se é o último
			self.corrente=0
		else:
			self.corrente+=1
		return retorno


lc = LCirc()
lc.append(1)
lc.append(2)
lc.append(3)
lc.append(4)
lc.append(5)
