defmodule Livro do
  def palavras do
    File.read!("dom_casmurro.txt")
    |> String.downcase()
    |> String.replace(~r/[^[:alpha:]\s]/u, " ")
    |> String.split()
  end

  def palindrome?(palavra) do
    palavra == String.reverse(palavra)
  end
end

# === NÃO MEXA DAQUI PRA CIMA, OS EXERCÍCIOS ESTÃO ABAIXO

# ==========================================
# EXEMPLO RESOLVIDO
# 20 maiores palavras distintas do livro
# ==========================================

resultado =
  Livro.palavras()
  |> Enum.uniq()
  |> Enum.sort_by(&String.length/1, :desc)
  |> Enum.take(20)

IO.inspect(resultado)

# descomente os exercícios e implemente eles:
# ==========================================
# EXERCÍCIO 1
# 20 palavras mais frequentes
# ==========================================

resultado =
  Livro.palavras()
  |> Enum.frequencies()
  |> Enum.sort_by(&elem(&1, 1), :desc)
  |> Enum.take(20)

IO.inspect(resultado)

# Dicas:
#
# Enum.frequencies()
# Enum.sort_by()
# Enum.take()

# ==========================================
# EXERCÍCIO 2
# Maior palíndromo do livro
# ==========================================

resultado =
  Livro.palavras()
  |> Enum.uniq()
  |> Enum.filter(&Livro.palindrome?/1)
  |> Enum.max_by(&String.length/1)

IO.inspect(resultado)

# Dicas:
#
# Enum.uniq()
# Enum.filter()
# Enum.max_by()
# Livro.palindrome?()
# String.length()

# ==========================================
# EXERCÍCIO 3
# Quantas palavras possuem mais de 10 letras?
# ==========================================

resultado =
  Livro.palavras()
  |> Enum.filter(&(String.length(&1)) > 10)
  |> Enum.count()

IO.inspect(resultado)

# Dicas:
#
# Enum.filter()
# Enum.count()
# String.length()
