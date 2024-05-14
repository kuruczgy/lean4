import Lean

open Lean Elab Tactic in
elab "revert_all" : tactic => do
  liftMetaTactic1 (·.revertAll)

example {α : Type u} [Inhabited α] (a : α) (f : α → α) (h : f a = default) : default = f a := by
  revert_all
  guard_target =ₛ∀ {α : Type u} [inst : Inhabited α] (a : α) (f : α → α), f a = default → default = f a
  intro α inst a f h
  exact h.symm

example (a b : α) (h₁ : a = b) (f g : α → α) (h₂ : ∀ x, f x = x) (h₃ : ∀ x, g x = f x) : ∃ x : α, f x = a ∧ g x = b := by
  apply Exists.intro
  revert_all
  intro β a₁ a₂ h f₁ f₂ h' h''
  constructor
  · exact h' a₁
  · rw [h'', h]; exact h' a₂
