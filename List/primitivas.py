class Node(object):       
    def __init__(self, val, nt = None):
        self.val = val
        self.next_node = nt
        
    def get_next(self):
        return self.next_node
			
    def set_next(self, n):
        self.next_node = n
	
    def get_val(self):
	    return self.val
	
    def set_val(self, v):
	    self.val = v

class LinkedList(object):
	def __init__(self, r = None):
		self.root = r
		self.size = 0
	
	def get_size(self):
		return self.size
		
	def add(self, d):
		new_node = Node(d, self.root)
		self.root = new_node
		self.size +=1	
		#quando adiciona o segundo nodo não tem que fazer new_node.set_next() = self.root e depois self.root = new_node?
	
	def remove(self, d):
		this_node = self.root
		prev_node = None		
		
		while this_node:
			if this_node.get_val() == d:
				if prev_node:
					prev_node.set_next(this_node.get_next())
				else: #não entendi esse passo! Não deveria ser self.root = this_node.get_next()
					self.root = this_node
				self.size -=1
				return True
			else:
				prev_node = this_node
				this_node = this_node.get_next()
		return False
		
	def find(self, d):
		this_node = self.root
		while this_node:
			if this_node.get_val() == d:
				return d #não era bom retornar o nodo?
			else:
				this_node = this_node.get_next()
		return None

myList = LinkedList()
myList.add(5)
myList.add(8)
myList.add(12)
myList.remove(8)
print(myList.remove(12))
print(myList.find(5))
					
					
					
					
					
					
		
		
		
