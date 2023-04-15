#include <iostream>
using namespace std;

int idCliente, idFuncionario, idProduto, quant = 0, cpf, cpf2;
float MAIOR = 0, total = 0;

struct Cliente{
	int id;
	string nome;
	int telefone;
	int cpf;
};

Cliente cadastroCliente[10];

struct Vendas{
	int id;
	int id_cliente;
	int id_funcionario;
	int id_produto;
	int quantidade;
	string data_saida;
};

Vendas vetorVendas[10];

struct Produto{
	int id;
	string nome;
	int quantidade;
	float valor;
};

Produto vetorProduto[10];

struct Funcionario{
	int id;
	string nome;
	int telefone;
	int cpf;
};

Funcionario vetorFuncionario[10];

void verificacaoEspecifica(){
	int loop2 = 0;
		cout << " Digite o cpf do cliente: ";
		cin >> cpf;
	do{
		for(int i=0; i < 10; i++){
			for(int j=0; j < 10; j++){
				if(vetorVendas[i].id_cliente == cadastroCliente[j].id){
					if(cpf == cadastroCliente[j].cpf){
						cout << "\n O ID da compra foi " << vetorVendas[i].id << ".\n";
						cout << " Comprou o produto com o ID " << vetorVendas[i].id_produto << ".\n";
						cout << " A quantidade comprada foi " << quant << " unidades.\n";
						cout << " Compra efetuada pelo funcionário com o ID " << vetorVendas[i].id_funcionario << ".\n";
						system("pause");
						loop2++;
					}
				}
			} 
		}
		if(loop2 == 0){
			cout << " \n Cpf do cliente não encontrado. Digite um válido: ";
			cin >> cpf; 
		}
	}while(loop2 == 0);
	
}

void verificacaoEspecificaFuncionario(){
	int loop3 = 0;
		cout << " Digite o cpf do funcionário: ";
		cin >> cpf2;
	do{
		for(int i=0; i < 10; i++){
			for(int j=0; j < 10; j++){
				if(vetorVendas[i].id_funcionario == vetorFuncionario[j].id){
					if(cpf2 == vetorFuncionario[j].cpf){
						cout << "\n O ID da venda realizada foi " << vetorVendas[i].id << ".\n";
						cout << " Vendeu o produto com o ID " << vetorVendas[i].id_produto << ".\n";
						cout << " A quantidade vendida foi " << quant << " unidades.\n";
						cout << " Vendeu para o cliente com o ID " << vetorVendas[i].id_cliente << ".\n";
						system("pause");
						loop3++;
					} 
				}
			} 
		}
		if(loop3 == 0){
			cout << " \n Cpf do funcionário não encontrado. Digite um válido: ";
			cin >> cpf2; 
		}
	}while(loop3 == 0);
	
}

float verificarTotal(){
	for(int i=0; i < 10; i++){
		for(int j=0; j < 10; j++){
			if(vetorVendas[i].id_produto == vetorProduto[j].id){
				total += (vetorProduto[j].valor * quant);
			} 
		}
	}
	return total;
}

float verificarMaior(){
	for(int i=0; i < 10; i++){
		for(int j=0; j < 10; j++){
			if(vetorVendas[i].id_produto == vetorProduto[j].id){
				if(vetorProduto[j].valor > MAIOR){
					MAIOR = vetorProduto[j].valor;
				}
			}
		} 
	}
	return MAIOR * quant;
}

void menuRelatorio(){
	system("cls");
	cout << " ====================== " << endl;
	cout << "     MENU RELATÓRIO   " << endl;
	cout << " ====================== " << endl;
	cout << " 1 - Exibir a maior venda " << endl;
	cout << " 2 - Exibir o total de todas as vendas " << endl;
	cout << " 3 - Exibir a venda de um cliente específico " << endl;
	cout << " 4 - Exibir todas as vendas de um funcionário " << endl;	
	cout << " 5 - Voltar para o MENU PRINCIPAL " << endl;
}

void verificarRelatorio(){
	int op;
	
	do{
		menuRelatorio();
		cout << "\n Opção que deseja: ";
		cin >> op;
		cout << " \n";
		
		switch(op){
			case 1:
				cout << " Maior venda: R$" << verificarMaior() << endl;
				system("pause");
				break;
			case 2:
				cout << " Valor total de todas as vendas: R$" << verificarTotal() << endl;
				system("pause");
				break;
			case 3:  
				verificacaoEspecifica();
				break;
			case 4:
				verificacaoEspecificaFuncionario();
				break;
		}
		
	} while(op != 5);
}

void validarFuncionario(){
	for(int i=0; i < 10; i++){
		if(vetorFuncionario[i].id == idFuncionario){
			for(int j=0; j < 10; j++){
				if(vetorVendas[j].id_cliente == idCliente){
					vetorVendas[j].id_produto = idProduto;
					vetorVendas[j].id_funcionario = idFuncionario;
				}
			}
		}
	}	
}

void cadastroFuncionario(){
	for(int i=0; i < 10; i++){
		if(vetorFuncionario[i].nome == ""){
			cout << " Id do funcionário: ";
			cin >> vetorFuncionario[i].id;
			cout << " Nome do funcionário: ";
			cin >> vetorFuncionario[i].nome;
			cout << " Telefone do funcionário: ";
			cin >> vetorFuncionario[i].telefone;
			cout << " Cpf do funcionário: ";
			cin >> vetorFuncionario[i].cpf;
			break;
		}
	}
}

void validarProduto(){
	for(int i=0; i<10; i++){
		if(vetorProduto[i].id ==  idProduto){
			for(int j = 0; j < 10; j++){
				if(vetorVendas[j].id_cliente == idCliente){
					vetorVendas[j].id_produto = idProduto;
				}
			}
		}
	}
}

void cadastroProduto(){
	for(int i=0; i < 10; i++){
		if(vetorProduto[i].nome == ""){
			cout <<" Id do produto: ";
			cin >> vetorProduto[i].id;
			cout << " Nome do produto: ";
			cin >> vetorProduto[i].nome;
			cout << " Quantidade existente no estoque: ";
			cin >> vetorProduto[i].quantidade;
			cout << " Valor do produto: ";
			cin >> vetorProduto[i].valor;
			break;
		}
	}
}

void validarCliente(){
	for(int i=0; i < 10; i++){
		if(cadastroCliente[i].id == idCliente){
			vetorVendas[i].id_cliente = idCliente;
		}
	}
}

int verificarEstoque(){
		for(int i=0; i < 10; i++){
			if(idProduto == vetorProduto[i].id){
				if( (vetorProduto[i].quantidade - quant) < 0){
					return 1;
				}else{
					vetorProduto[i].quantidade = vetorProduto[i].quantidade - quant;
					return 0;
				}
			} 
	   }
}

void verificarVendas(){
	int loop = 0;
	for(int i=0; i < 10; i++){
		if(vetorVendas[i].data_saida == ""){
			cout << " Id: ";
			cin >> vetorVendas[i].id;
			cout << " Id do cliente: "; 
			cin >> idCliente;
			validarCliente();
			cout << " Id do funcionário: ";
			cin >> idFuncionario;
			validarFuncionario();
			cout << " Id do produto: ";
			cin >>  idProduto;
			validarProduto();
			cout << " Quantidade: ";
			cin >> quant;
			do{
				loop = verificarEstoque();
				if(loop == 1){
					cout << "\n Quantidade inválida. Escolha outra: ";
					cin >> quant;
				}else if(verificarEstoque() == 0){
					verificarEstoque();
				}	
			}while(loop == 1);

			cout << " Data de saída: ";
			cin >> vetorVendas[i].data_saida;
			break;
		}
	}
}

void verificarCadastroCliente(){
	for(int i=0; i <10; i++){
		if(cadastroCliente[i].nome == ""){
			cout << " Id do cliente: ";
			cin >> cadastroCliente[i].id;
			cout <<  " Nome do cliente: ";
			cin >> cadastroCliente[i].nome;
			cout << " Telefone do cliente: ";
			cin >> cadastroCliente[i].telefone;
			cout << " Cpf do cliente: ";
			cin >> cadastroCliente[i].cpf;
			break;
		}
	}
}

void menuCadastro(){
	system("cls");
	cout << " ===================== " << endl;
	cout << "     MENU CADASTRO   " << endl;
	cout << " ===================== " << endl;
	cout << " 1 - Cadastrar Cliente " << endl;
	cout << " 2 - Cadastrar Funcionário " << endl;
	cout << " 3 - Cadastrar Produto " << endl;
	cout << " 4 - Voltar para o MENU PRINCIPAL " << endl;
}

void verificarCadastro(){
	int op;
	
	do{
		menuCadastro();
		cout << "\n Opção que deseja: ";
		cin >> op;
		cout << " \n";
		
		switch(op){
			case 1:
				verificarCadastroCliente();
				break;
			case 2:
				cadastroFuncionario();
				break;
			case 3:
				cadastroProduto();
				break;
		}
	} while(op != 4);
} 

void menu(){
	system("cls");
	cout << "\n SEJA BEM-VINDO(A)! ";
	cout << "\n\n ====================== " << endl;
	cout << "     MENU PRINCIPAL   " << endl;
	cout << " ====================== " << endl;
	cout << " 1 - Cadastros " << endl;
	cout << " 2 - Vendas " << endl;
	cout << " 3 - Relatórios " << endl;
	cout << " 4 - Sair " << endl;
}
 
int main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	
	do{
		menu();
		cout << "\n Opção que deseja: ";
		cin >> op;
		cout << " \n";
		
		switch(op){
			case 1:
				verificarCadastro();
				break;
			case 2:
				verificarVendas();
				break;
			case 3:
				verificarRelatorio();
				break;
			case 4:
				cout << " Saindo...";
				break;	
		}
	} while(op != 4);
	
	return 0;
}


