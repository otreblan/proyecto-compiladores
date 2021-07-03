// Compilador
// Copyright © 2021 otreblan
//
// cce is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// cce is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with cce.  If not, see <http://www.gnu.org/licenses/>.

#include <cstdio>
#include <string_view>

#include <fmt/core.h>

#include "ast.h"
#include "graph.hpp"

template <typename T>
static void print_node(FILE* file, int n, const T& t);
static void print_edge(FILE* file, int n, int i);

static int str_graph(FILE* file, int n, std::string_view str);
static int id_graph(FILE* file, int n, std::string_view str);
static int char_graph(FILE* file, int n, char c);
static int num_graph(FILE* file, int n, int num);

static int addop_graph(FILE* file, int n, const ast_addop& addop);
static int args_graph(FILE* file, int n, const ast_args& args);
static int call_graph(FILE* file, int n, const ast_call& call);
static int declaracion_graph(FILE* file, int n, const ast_declaracion& declaracion);
static int declaracion_local_graph(FILE* file, int n, const ast_declaracion_local& declaracion_local);
static int expresion_aditiva_graph(FILE* file, int n, const ast_expresion_aditiva& expresion_aditiva);
static int expresion_graph(FILE* file, int n, const ast_expresion& expresion);
static int expresion_simple_graph(FILE* file, int n, const ast_expresion_simple& expresion_simple);
static int factor_graph(FILE* file, int n, const ast_factor& factor);
static int fun_declaracion_graph(FILE* file, int n, const ast_fun_declaracion& fun_declaracion);
static int lista_arg_graph(FILE* file, int n, const ast_lista_arg& lista_arg);
static int lista_declaracion_graph(FILE* file, int n, const ast_lista_declaracion& lista_declaracion);
static int lista_params_graph(FILE* file, int n, const ast_lista_params& lista_params);
static int lista_sentencias_graph(FILE* file, int n, const ast_lista_sentencias& lista_sentencias);
static int mulop_graph(FILE* file, int n, const ast_mulop& mulop);
static int param_graph(FILE* file, int n, const ast_param& param);
static int params_graph(FILE* file, int n, const ast_params& params);
static int relop_graph(FILE* file, int n, const ast_relop& relop);
static int sent_compuesta_graph(FILE* file, int n, const ast_sent_compuesta& sent_compuesta);
static int sentencia_expresion_graph(FILE* file, int n, const ast_sentencia_expresion& sentencia_expresion);
static int sentencia_graph(FILE* file, int n, const ast_sentencia& sentencia);
static int sentencia_iteracion_graph(FILE* file, int n, const ast_sentencia_iteracion& sentencia_iteracion);
static int sentencia_retorno_graph(FILE* file, int n, const ast_sentencia_retorno& sentencia_retorno);
static int sentencia_seleccion_graph(FILE* file, int n, const ast_sentencia_seleccion& sentencia_seleccion);
static int term_graph(FILE* file, int n, const ast_term& term);
static int tipo_graph(FILE* file, int n, const ast_tipo& tipo);
static int var_declaracion_graph(FILE* file, int n, const ast_var_declaracion& var_declaracion);
static int var_graph(FILE* file, int n, const ast_var& var);

template <typename T>
static void print_node(FILE* file, int n, const T& t)
{
	fmt::print(file, "\t {} [label=\"{}\"];\n", n, t);
}

static void print_edge(FILE* file, int n, int i)
{
	fmt::print(file, "\t {} -> {};\n", n, i);
}

static int addop_graph(FILE* file, int n, const ast_addop& addop)
{
	int i = n;
	return i;
}

static int args_graph(FILE* file, int n, const ast_args& args)
{
	int i = n;
	return i;
}

static int call_graph(FILE* file, int n, const ast_call& call)
{
	int i = n;
	return i;
}

static int declaracion_graph(FILE* file, int n, const ast_declaracion& declaracion)
{
	int i = n;
	print_node(file, n, "declaracion");

	switch(declaracion.tipo)
	{
	case AST_VAR_DECLARACION:
		if(declaracion.var)
		{
			print_edge(file, n, i+1);
			i = var_declaracion_graph(file, i+1, *declaracion.var);
		}
		break;

	case AST_FUN_DECLARACION:
		if(declaracion.fun)
		{
			print_edge(file, n, i+1);
			i = fun_declaracion_graph(file, i+1, *declaracion.fun);
		}
		break;
	}
	return i;
}

static int declaracion_local_graph(FILE* file, int n, const ast_declaracion_local& declaracion_local)
{
	int i = n;
	return i;
}

static int expresion_aditiva_graph(FILE* file, int n, const ast_expresion_aditiva& expresion_aditiva)
{
	int i = n;
	return i;
}

static int expresion_graph(FILE* file, int n, const ast_expresion& expresion)
{
	int i = n;
	return i;
}

static int expresion_simple_graph(FILE* file, int n, const ast_expresion_simple& expresion_simple)
{
	int i = n;
	return i;
}

static int factor_graph(FILE* file, int n, const ast_factor& factor)
{
	int i = n;
	return i;
}

static int fun_declaracion_graph(FILE* file, int n, const ast_fun_declaracion& fun_declaracion)
{
	int i = n;
	return i;
}

static int lista_arg_graph(FILE* file, int n, const ast_lista_arg& lista_arg)
{
	int i = n;
	return i;
}

static int lista_declaracion_graph(FILE* file, int n, const ast_lista_declaracion& lista_declaracion)
{
	int i = n;

	print_node(file, n, "lista_declaracion");

	if(lista_declaracion.declaracion)
	{
		print_edge(file, n, i+1);
		i = declaracion_graph(file, i+1, *lista_declaracion.declaracion);
	}

	if(lista_declaracion.next)
	{
		print_edge(file, n, i+1);
		i = lista_declaracion_graph(file, i+1, *lista_declaracion.next);
	}

	return i;
}

static int lista_params_graph(FILE* file, int n, const ast_lista_params& lista_params)
{
	int i = n;
	return i;
}

static int lista_sentencias_graph(FILE* file, int n, const ast_lista_sentencias& lista_sentencias)
{
	int i = n;
	return i;
}

static int mulop_graph(FILE* file, int n, const ast_mulop& mulop)
{
	int i = n;
	return i;
}

static int param_graph(FILE* file, int n, const ast_param& param)
{
	int i = n;
	return i;
}

static int params_graph(FILE* file, int n, const ast_params& params)
{
	int i = n;
	return i;
}

static int relop_graph(FILE* file, int n, const ast_relop& relop)
{
	int i = n;
	return i;
}

static int sent_compuesta_graph(FILE* file, int n, const ast_sent_compuesta& sent_compuesta)
{
	int i = n;
	return i;
}

static int sentencia_expresion_graph(FILE* file, int n, const ast_sentencia_expresion& sentencia_expresion)
{
	int i = n;
	return i;
}

static int sentencia_graph(FILE* file, int n, const ast_sentencia& sentencia)
{
	int i = n;
	return i;
}

static int sentencia_iteracion_graph(FILE* file, int n, const ast_sentencia_iteracion& sentencia_iteracion)
{
	int i = n;
	return i;
}

static int sentencia_retorno_graph(FILE* file, int n, const ast_sentencia_retorno& sentencia_retorno)
{
	int i = n;
	return i;
}

static int sentencia_seleccion_graph(FILE* file, int n, const ast_sentencia_seleccion& sentencia_seleccion)
{
	int i = n;
	return i;
}

static int term_graph(FILE* file, int n, const ast_term& term)
{
	int i = n;
	return i;
}

static int tipo_graph(FILE* file, int n, const ast_tipo& tipo)
{
	int i = n;
	print_node(file, n, "tipo");

	switch(tipo.tipo)
	{
	case AST_SIN_TIPO:
		print_edge(file, n, i+1);
		i = str_graph(file, i+1, "sin_tipo");
		break;

	case AST_ENTERO:
		print_edge(file, n, i+1);
		i = str_graph(file, i+1, "entero");
		break;
	}

	return i;
}

static int var_declaracion_graph(FILE* file, int n, const ast_var_declaracion& var_declaracion)
{
	int i = n;
	print_node(file, n, "var_declaracion");

	if(var_declaracion.tipo)
	{
		print_edge(file, n, i+1);
		i = tipo_graph(file, i+1, *var_declaracion.tipo);
	}

	if(var_declaracion.id)
	{
		print_edge(file, n, i+1);
		i = id_graph(file, i+1, var_declaracion.id);
	}

	if(var_declaracion.es_arreglo)
	{
		print_edge(file, n, i+1);
		i = char_graph(file, i+1, '[');

		print_edge(file, n, i+1);
		i = num_graph(file, i+1, var_declaracion.num);

		print_edge(file, n, i+1);
		i = char_graph(file, i+1, ']');
	}

	print_edge(file, n, i+1);
	i = char_graph(file, i+1, ';');

	return i;
}

static int var_graph(FILE* file, int n, const ast_var& var)
{
	int i = n;
	return i;
}

static int str_graph(FILE* file, int n, std::string_view str)
{
	print_node(file, n, str);
	return n;
}

static int id_graph(FILE* file, int n, std::string_view str)
{
	fmt::print(file, "\t {} [label=\"\\\"{}\\\"\"];\n", n, str);
	return n;
}

static int char_graph(FILE* file, int n, char c)
{
	fmt::print(file, "\t {} [label=\"'{}'\"];\n", n, c);
	return n;
}

static int num_graph(FILE* file, int n, int num)
{
	print_node(file, n, num);
	return n;
}

void cce::ast_graph(FILE* file, const ast_programa* programa)
{
	int n = 0;
	int i = n;
	fmt::print(file, "{}\n", "digraph D {");

	if(programa)
	{
		print_node(file, n, "programa");
		if(programa->lista_declaraciones)
		{
			print_edge(file, n, i+1);
			i = lista_declaracion_graph(file, i+1, *programa->lista_declaraciones);
		}
	}

	fmt::print(file, "{}\n", "}");
}
